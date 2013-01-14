#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "debugmode.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QTextEdit>
#include <QFile>
#include <QDateTime>
#include <QHostAddress>
#include <QNetworkInterface>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
private:
		Ui::MainWindow *ui;
		QFile* fileHandler;
		int intPort;
		int extPort;
		QHostAddress localIP;

		bool isOnline;
		bool isIPV4Address(QString address);
		void loadConfig();
		void writeConfig();
private slots:
		void on_buttonRun_clicked();
		void on_buttonStop_clicked();
		void on_buttonRestart_clicked();
		void on_actionRun_triggered();
		void on_actionStop_triggered();
		void on_actionRestart_triggered();
		void on_actionSaveCfg_triggered();
		void on_actionLoad_triggered();
		void on_actionQuit_triggered();
		void on_actionHelp_triggered();
		void on_actionAbout_triggered();

	public slots:
		void slot_serverMessenger(QString disp);
		void slot_serverStarted(bool isStarted);
signals:
		void signal_startServer(int external, int internal, QHostAddress serverIP);
		void signal_stopServer();
		void signal_quit();
};

#endif // MAINWINDOW_H
