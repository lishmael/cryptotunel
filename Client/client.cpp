#include "client.h"

Client::Client()
{
	connect(this, SIGNAL(signal_display(QString)),
			this, SLOT(slot_display(QString)));

	loadConfig();
	databaseConnectionEstablished = false;

	//Local app connection
	localServer = new QTcpServer(this);
	if (!localServer->listen(QHostAddress::LocalHost, localPort))
	{
		localServer->close();
		emit signal_display("Local server starting error: " +
							localServer->errorString());
	}
	connect(localServer, SIGNAL(newConnection()),
			this, SLOT(slot_newDatabaseConnection()));
	emit signal_display(QString("Internal server is ready at ") +
						localServer->serverAddress().toString() +
						" : " +
						QString::number(localServer->serverPort()));

	// Encription server connection
	connectToServer();

}
void Client::connectToServer()
{
	serverSocket = new QTcpSocket(this);
	serverSocket->connectToHost(serverAddress, externalPort);
	connect(serverSocket, SIGNAL(connected()),
			this, SLOT(slot_connectedToServer()));
	connect(serverSocket, SIGNAL(readyRead()),
			this, SLOT(slot_readServer()));
	connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(slot_connectionError(QAbstractSocket::SocketError)));
	connect(serverSocket, SIGNAL(disconnected()),
			this, SLOT(slot_tunnelBroken()));
	connect(this, SIGNAL(signal_serverReadError()),
			this, SLOT(slot_needResendData()));
}
void Client::loadConfig()
{
	fileHandler = new QFile("client.jpg");
	if (fileHandler->open(QFile::ReadOnly) && fileHandler->exists())
	{
		QString line;
		localPort = -1;
		externalPort = -1;
		QByteArray buffer;
		while (true)
		{
			buffer.clear();
			line.clear();
			buffer = fileHandler->readLine();
			if (buffer.count() == 0) break;
			line = QString(buffer);
#ifdef DEBUG
			std::cout << line.toStdString() << std::endl;
#endif
			QStringList inputRow = line.split(" ", QString::SkipEmptyParts);
			if (inputRow[0] == "@LocalPort")
			{
				localPort = inputRow[1].toInt();
			}
			else if (inputRow[0] == "@ExternalPort")
			{
				externalPort = inputRow[1].toInt();
			}
			else if (inputRow[0] == "@ServerIP")
			{
				serverAddress = inputRow[1];
			}
			else
			{
				continue;
			}
		}
		fileHandler->close();
	}
	else emit signal_display(QString("Cannot open client configuration file!"));
	delete fileHandler;
}
void Client::slot_readServer()
{
	QByteArray data;
	while (serverSocket->bytesAvailable() > 0)
	{
		data.append(serverSocket->readAll());
	}
	if (QByteArray("ASfgsiopgwqhejadfk[0qwu29ujis;vlasdf") == data)
	{
		sendToServer(currentData);
		return;
	}
#ifdef DEBUG
	cout << "Incoming message: " << data.count() << " bytes. Message is: " << endl;
	cout.write(data.data(), data.count());
	cout << endl;
#endif
	if (!messageDecrypt(data) || data.count() == 0)
	{
		emit signal_serverReadError();
		return;
	}
	QString disp = "Incoming data from server: " +
					QString::number(data.count()) +
					" bytes.";
#ifdef DEBUG
	disp += " Data is: <" + QString(data) + ">";
#endif
	emit signal_display(disp);
	writeToDatabase(data);
}

void Client::slot_needResendData()
{
	serverSocket->write("AaAaAa121212@#@!@#");
}

void Client::slot_tunnelBroken()
{
	emit signal_display("Tunnel closed");
}

void Client::slot_connectionError(QAbstractSocket::SocketError)
{
	emit signal_display("Connection error: " +
						((QTcpSocket*)sender())->errorString());
	emit signal_done();
}

void Client::sendToServer(QByteArray &message)
{
	if (!messageEncrypt(message) || message.count() == 0)
	{
		signal_display("Encryption error!");
		return;
	}
	serverSocket->write(message);
	while (serverSocket->bytesToWrite() > 0)
	{
		serverSocket->flush();
	}
	signal_display(QString::number(message.count()) +
				   " bytes was sent to serever");
}
void Client::slot_connectedToServer()
{
	emit signal_display("Connected to server");
}

void Client::slot_display(QString msg)
{
	QString endl = "\r\n";
#ifndef Q_WS_WIN
	endl = "\n";
#endif
	QString logString = QDateTime::currentDateTime().toString("[dd.MM.yyyy hh:mm:ss.zzz] ");
	fileHandler =  new QFile("client.log");
	if (fileHandler->open(QFile::WriteOnly | QFile::Append))
	{
		logString += msg;
		fileHandler->write((logString + endl).toStdString().c_str());
		fileHandler->close();
	}
	else
	{
		logString += "Logging error! Error writing 'client.log' file!";
	}
	delete fileHandler;
	std::cout << logString.toStdString() << std::endl;
}

Client::~Client()
{
//	delete serverSocket;
//	delete localServer;
}

void Client::slot_newDatabaseConnection()
{

	if (databaseConnectionEstablished)
	{
		databaseClientSocket->deleteLater();
	}
	databaseConnectionEstablished = true;
	databaseClientSocket = localServer->nextPendingConnection();
	connect(databaseClientSocket, SIGNAL(readyRead()),
			this, SLOT(slot_readDatabase()));
	connect(databaseClientSocket, SIGNAL(disconnected()),
			this, SLOT(slot_databaseDisconnected()));

}

void Client::slot_readDatabase()
{
	QByteArray recivedData;
	while (databaseClientSocket->bytesAvailable() > 0)
	{
		QByteArray buffer = databaseClientSocket->readAll();
		recivedData.append(buffer);
	}
	if (recivedData.count() == 0) return;
	emit signal_display("Recived " +
						QString::number(recivedData.count()) +
						" bytes of data from client");
#ifdef DEBUG
	emit signal_display("Data from internal: " + QString(recivedData));
#endif
	currentData = recivedData;
	sendToServer(recivedData);
}

void Client::slot_databaseDisconnected()
{
	databaseConnectionEstablished = false;
	((QTcpSocket*)sender())->deleteLater();
	emit signal_display("Disconnected from external app");
}

void Client::writeToDatabase(QByteArray data)
{
	if (databaseConnectionEstablished)
	{
		databaseClientSocket->write(data);
		while (databaseClientSocket->bytesToWrite() > 0)
		{
			databaseClientSocket->flush();
		}
	}
}

bool Client::messageEncrypt(QByteArray &data)
{
	if (The_Crypt::to_the_crypt(data) != 0)
	{
		return false;
	}
	return true;
}

bool Client::messageDecrypt(QByteArray &data)
{
	if (The_Crypt::from_the_crypt(data) != 0)
	{
		return false;
	}
	return true;
}


