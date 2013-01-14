#ifndef SERVER_H
#define SERVER_H

#include "debugmode.h"

#include <QtNetwork/QtNetwork>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <QMessageBox>
#include <QHash>
#include <string>
#include <QNetworkInterface>
#include <QThread>

#include "cipherer.h"

class Server;

class Thread : public QThread
{
		Q_OBJECT
	public:
		enum Mode { read_DB, read_Cli };
		Thread(Server* serv, Mode mod, QTcpSocket* sock);
		void stop();
	protected:
		void run();
	private:
		volatile bool isRun;
		Server* srv;
		Mode mode;
		QTcpSocket* socket;
	signals:

	public slots:

};

class Server : public QWidget
{
	Q_OBJECT
		friend class Thread;
	private:
		QList<Thread*> threads;
		QTcpServer* externalServer;
		QHostAddress localAddress;
		int externalPort;
		int localPort;
		QList<QTcpSocket*> clientSocketsConnected;
		QList<QTcpSocket*> databaseSocketsConnected;
//		QHash<QTcpSocket*, QTcpSocket*> tunnels;
		QMap<QTcpSocket*, QByteArray> openData;
		bool startServer();
		void sendToClient(QTcpSocket* pSocket,
						  QByteArray data);
		void sendToDatabase(QTcpSocket *clientFrom,
							QByteArray data);
		void clientDisconnect(QTcpSocket *cli);
		bool messageEncrypt(QByteArray &data);
		bool messageDecrypt(QByteArray &data);
		bool isIPV4Address(QString address);
		int readClient(QTcpSocket *clientSenderSocket,
					   QByteArray &data);
		int readDatabase(QTcpSocket *databaseSocket,
						 QByteArray &recivedData);
	public:
		Server();
		~Server();
	private slots:
		void slot_newConnection();
		void slot_readCient();
		void slot_readDatabase();
		void slot_clientDisconnected();
		void slot_dbDisconnected();
		void slot_socketError();
	public slots:
		void slot_startServer(int externalPort, int localPort,
							  QHostAddress serverIP);
		void slot_stopServer();
		void slot_needResendData();
	signals:
		void signal_startServerError(QString);
		void signal_display(QString);
		void signal_serverStaus(bool isOnline);
		void singal_messageDataError(QTcpSocket *mesSender);
};



#endif // SERVER_H
