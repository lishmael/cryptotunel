#ifndef CLIENT_H
#define CLIENT_H

#include "../Server/debugmode.h"

#include <QtNetwork/QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include "cipherer.h"

#ifdef WIN32
#include <Winsock2.h>
#else
#include <sys/socket.h>
#endif

class Client : public QObject
{
	Q_OBJECT
private:
	QTcpSocket* serverSocket; // Socket used to communicate with our server
	QTcpSocket* databaseClientSocket; // Socket used to communicate with external application
	QTcpServer* localServer; // Server used to allow external application to connect
	QFile* fileHandler; // Used to operate with config and log files
	QString serverAddress; // Our server addresss
	QByteArray currentData; // Current data to be transmitted to server
	int externalPort; // Port used to communicate with our server
	int localPort; // Port used to communicate with externall app
	bool databaseConnectionEstablished; // Represents state of connection with external app
	void connectToServer();
	void loadConfig(); // Loads client configuration from file
	bool messageEncrypt(QByteArray &data); // Encrypts data
	bool messageDecrypt(QByteArray &data); // Decrypts data
	void writeToDatabase(QByteArray data); // Sends data to external app
	void sendToServer(QByteArray &message); // Sends data to our server
public:
	Client(); // Initializes sockets; loads data; connects to server
	~Client();
private slots:
	void slot_display(QString msg); // Displays message & writes it to log
	void slot_connectionError(QAbstractSocket::SocketError); // call when connection error occures
	void slot_connectedToServer(); // called when connection to server is established
	void slot_readServer(); // called when server socket has data to be read
	void slot_needResendData(); // called when data transfer error occurs
	void slot_tunnelBroken(); // called when connection between our server and client is lost
	void slot_newDatabaseConnection(); // called when
	void slot_readDatabase(); // called when database socket has data to be read
	void slot_databaseDisconnected(); // called when database has disconnected
signals:
	void signal_display(QString msg); // emited to display message
	void signal_serverReadError(); // emited to signal about data transfer error
	void signal_done(); // emited to quit
};

#endif // CLIENT_H
