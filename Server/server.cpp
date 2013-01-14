#include "server.h"

Server::Server()
{
	externalServer = new QTcpServer(this);
	connect(externalServer, SIGNAL(newConnection()),
			this, SLOT(slot_newConnection()));
	connect(this, SIGNAL(singal_messageDataError(QTcpSocket*)),
            this, SLOT(slot_needResendData()));
}

Server::~Server()
{
	delete externalServer;
}

bool Server::startServer()
{
	if (!externalServer->listen(localAddress, externalPort))
	{
		externalServer->close();
        emit signal_startServerError("External server ing error: " +
									 externalServer->errorString());
		return false;
	}

	emit signal_display(QString("External server ed successfully at ") +
						externalServer->serverAddress().toString() +
						" : " +
						QString::number(externalServer->serverPort()));
	return true;
}

void Server::slot_newConnection()
{
	QTcpSocket* pClientSocket = externalServer->nextPendingConnection();
//	if (tunnels.find(pClientSocket) == tunnels.end())
//	{
//		QTcpSocket *dbConnect = new QTcpSocket();
//		dbConnect->connectToHost("localhost", localPort);
//		if (!dbConnect->waitForConnected())
//		{
//			emit signal_display("Cannot connect to database!");
//			dbConnect->deleteLater();
//			return;
//		}

//	}

	if (clientSocketsConnected.indexOf(pClientSocket) == -1)
	{
		databaseSocketsConnected.push_back(new QTcpSocket());
		databaseSocketsConnected.last()->connectToHost("localhost",localPort);
		if (!databaseSocketsConnected.last()->waitForConnected())
		{
			emit signal_display("Cannot connect to database!");
			databaseSocketsConnected.last()->deleteLater();
			databaseSocketsConnected.pop_back();
			return;
		}
		connect(databaseSocketsConnected.last(), SIGNAL(readyRead()),
				this, SLOT(slot_readDatabase()));
		connect(databaseSocketsConnected.last(), SIGNAL(disconnected()),
				this, SLOT(slot_dbDisconnected()));
		connect(databaseSocketsConnected.last(), SIGNAL(error(QAbstractSocket::SocketError)),
				this, SLOT(slot_socketError()));
		clientSocketsConnected.push_back(pClientSocket);
		connect(clientSocketsConnected.last(), SIGNAL(readyRead()),
				this, SLOT(slot_readCient()));
		connect(clientSocketsConnected.last(), SIGNAL(disconnected()),
				this, SLOT(slot_clientDisconnected()));


		QString disp = "New client connected: "
				+ clientSocketsConnected.last()->peerAddress().toString();
		emit signal_display(disp);
	}
}

void Server::slot_readCient()
{

	QTcpSocket* clientSenderSocket = (QTcpSocket*)sender();
	threads.push_back(new Thread(this, Thread::read_Cli, clientSenderSocket));
    threads.last()->start();
//	QByteArray data;
//	readClient(clientSenderSocket, data);
//	sendToDatabase(clientSenderSocket, data);
}
int Server::readClient(QTcpSocket* clientSenderSocket,
					   QByteArray &data)
{
	while (clientSenderSocket->bytesAvailable() > 0)
	{
		data.append(clientSenderSocket->readAll());
	}
	if (QByteArray("AaAaAa121212@#@!@#") == data)
	{
		this->sendToClient(clientSenderSocket, openData[clientSenderSocket]);
#ifdef DEBUG2
		cout << "detected error. resending data" << endl;
#endif
		return -1;
	}
	if (!messageDecrypt(data) || data.count() == 0)
	{
		emit singal_messageDataError(clientSenderSocket);
		return -2;
	}
	QString strMessage = "Recived " +
						 QString::number(data.count()) +
						 " bytes of data from " +
						 clientSenderSocket->peerAddress().toString() + " (Client)";
#ifdef DEBUG
	strMessage += " Data is: <" + QString(data) + ">";
#endif
	emit signal_display(strMessage);
	return 0;
}


void Server::slot_clientDisconnected()
{
	QTcpSocket *cli  = (QTcpSocket*)sender();
	while (clientSocketsConnected.contains(cli))
	{
		int n = clientSocketsConnected.indexOf(cli);
		emit signal_display("Client "
							+ clientSocketsConnected.at(n)->peerAddress().toString()
							+ " has disconnected");
		clientSocketsConnected.at(n)->deleteLater();
		databaseSocketsConnected.at(n)->deleteLater();
		clientSocketsConnected.removeAt(n);
		databaseSocketsConnected.removeAt(n);
	}
}

void Server::slot_dbDisconnected()
{
	//
}

void Server::slot_socketError()
{
//    if (((QTcpSocket*)sender())->errorString())
	QTcpSocket *tmp = (QTcpSocket*)sender();
	int n = databaseSocketsConnected.indexOf(tmp);
	if (-1 != n)
	{
		databaseSocketsConnected.at(n)->deleteLater();
		databaseSocketsConnected[n] = new QTcpSocket();
		databaseSocketsConnected[n]->connectToHost("localhost",localPort);
		if (!databaseSocketsConnected[n]->waitForConnected())
		{
			emit signal_display("Cannot connect to database!");
			clientDisconnect(clientSocketsConnected.at(n));
			return;
		}
		connect(databaseSocketsConnected.last(), SIGNAL(readyRead()),
				this, SLOT(slot_readDatabase()));
		connect(databaseSocketsConnected.last(), SIGNAL(disconnected()),
				this, SLOT(slot_dbDisconnected()));
		connect(databaseSocketsConnected.last(), SIGNAL(error(QAbstractSocket::SocketError)),
				this, SLOT(slot_socketError()));
	}
}

void Server::slot_needResendData()
{
	((QTcpSocket*)sender())->write("ASfgsiopgwqhejadfk[0qwu29ujis;vlasdf");
}

void Server::sendToClient(QTcpSocket *pSocket,
						  QByteArray data)
{
//	int tmp = data.count();
	if (!messageEncrypt(data))
	{
		emit signal_display("Encryption error!");
		return;
	}
//	tmp = data.count();
	pSocket->write(data);
	while (pSocket->bytesToWrite() > 0)
	{
		pSocket->flush();
		// Wait for data sent
	}
	QString strMessage = "Server has sent to the " +
						 pSocket->peerAddress().toString() + " " +
						 QString::number(data.count()) +
						 " bytes of data.";
#ifdef DEBUG
	strMessage += " Data is: <" + QString(data) + ">";
#endif
	emit signal_display(strMessage);
}

void Server::sendToDatabase(QTcpSocket *clientFrom,
							QByteArray data)
{
	int n = clientSocketsConnected.indexOf(clientFrom);
	if (-1 != n)
	{
		int amount = databaseSocketsConnected.at(n)->write(data);
		while (databaseSocketsConnected.at(n)->bytesToWrite() > 0)
		{
			databaseSocketsConnected.at(n)->flush();
		}
		emit signal_display(QString::number(amount) +
							" was sent do (DB)");
	}
}

void Server::clientDisconnect(QTcpSocket *cli)
{
	while (clientSocketsConnected.contains(cli))
	{
		int n = clientSocketsConnected.indexOf(cli);
		emit signal_display("Client "
							+ clientSocketsConnected.at(n)->peerAddress().toString()
							+ " has disconnected");
		clientSocketsConnected.at(n)->deleteLater();
		databaseSocketsConnected.at(n)->deleteLater();
		clientSocketsConnected.removeAt(n);
		databaseSocketsConnected.removeAt(n);
	}
}

void Server::slot_readDatabase()
{
	QTcpSocket *databaseSocket = (QTcpSocket*)sender();
	threads.push_back(new Thread(this, Thread::read_DB, databaseSocket));
    threads.last()->start();
//	QByteArray recivedData;
//	readDatabase(databaseSocket, recivedData);
//	int n = databaseSocketsConnected.indexOf(databaseSocket);
//	if (-1 != n)
//	{
//		if (openData.contains(clientSocketsConnected.at(n)))
//				openData[clientSocketsConnected.at(n)] = recivedData;
//		else
//				openData.insert(clientSocketsConnected.at(n), recivedData);
//		sendToClient(clientSocketsConnected.at(n), recivedData);
//	}
}
int Server::readDatabase(QTcpSocket *databaseSocket, QByteArray &recivedData)
{
	while (databaseSocket->bytesAvailable() > 0)
	{
		recivedData.append(databaseSocket->readAll());
	}
	emit signal_display("Recived: " +
						QString::number(recivedData.count()) +
						QString(" bytes of data from internal server (DB)"));
#ifdef DEBUG
	emit signal_display("Data is: \n" + QString(recivedData) + "\n");
#endif
	return 0;
}
bool Server::messageEncrypt(QByteArray &data)
{
	if (The_Crypt::to_the_crypt(data) != 0)
	{
		return false;
	}
	return true;
}

bool Server::messageDecrypt(QByteArray &data)
{
	if (The_Crypt::from_the_crypt(data) != 0)
	{
		return false;
	}
	return true;
}

bool Server::isIPV4Address(QString address)
{
	QStringList listAddress = address.split(".",QString::SkipEmptyParts);
	if (listAddress.count() != 4) return false;
	bool ok = false;
	for (int i = 0; i < 4; ++i)
	{
		int a = QString(listAddress[i]).toInt(&ok);
		if (!(ok && (a >= 0) && (a <= 255))) return false;
	}
	return true;
}



void Server::slot_startServer(int externalPort,
						 int localPort,
						 QHostAddress serverIP)
{
	this->externalPort = externalPort;
	this->localPort = localPort;
	this->localAddress = serverIP;
    emit signal_serverStaus(startServer());
}

void Server::slot_stopServer()
{
	for (int i = 0; i < clientSocketsConnected.count(); ++i)
	{
		if (clientSocketsConnected[i] != NULL)
		{
			clientSocketsConnected[i]->deleteLater();
			databaseSocketsConnected[i]->deleteLater();
		}
	}
	clientSocketsConnected.clear();
	databaseSocketsConnected.clear();
	externalServer->close();
	emit signal_serverStaus(false);
	emit signal_display(QString("Server is down"));
}


Thread::Thread(Server *serv,
			   Thread::Mode mod,
			   QTcpSocket* sock)
{
	srv = serv;
	mode = mod;
	isRun = true;
	socket = sock;
}


void Thread::run()
{
	switch (mode)
	{
		case read_DB:
		{
			if (isRun)
			{
				QByteArray recivedData;
				srv->readDatabase(socket, recivedData);
				int n = srv->databaseSocketsConnected.indexOf(socket);
				if (-1 != n)
				{
					if (srv->openData.contains(srv->clientSocketsConnected.at(n)))
							srv->openData[srv->clientSocketsConnected.at(n)] = recivedData;
					else
							srv->openData.insert(srv->clientSocketsConnected.at(n), recivedData);
					srv->sendToClient(srv->clientSocketsConnected.at(n), recivedData);
				}
			}
			break;
		}
		case read_Cli:
		{
			if (isRun)
			{
				QByteArray data;
				srv->readClient(socket, data);
				srv->sendToDatabase(socket, data);
			}
			break;
		}
		default:
			break;
	}
	srv->threads.removeAll(this);
	this->deleteLater();
}
