#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QLineEdit* to1 = centralWidget()->findChild<QLineEdit*>("inputExtPort");
	QLineEdit* to2 = centralWidget()->findChild<QLineEdit*>("inputIntPort");
	QWidget::setTabOrder(to1, to2);
	to1->setFocus();
	loadConfig();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::loadConfig()
{
	fileHandler = new QFile("server.jpg");
	intPort = -1;
	extPort = -1;
	QString line;
	if (fileHandler->open(QFile::ReadOnly) && fileHandler->exists())
	{
		line.clear();
		QByteArray bLine;
		while (true)
		{
			bLine = fileHandler->readLine();
			if (bLine.count() > 0)
			{
				line.append(bLine);
				QStringList inputRow = line.split(" ", QString::SkipEmptyParts);
				line.clear();
				bool data_ok = true;
				if (inputRow.count() > 1)
				{
					if (inputRow[0] == "@LocalPort")
					{
						intPort = inputRow[1].toInt(&data_ok);
						if (!data_ok) intPort = -1;
					}
					else if (inputRow[0] == "@ExternalPort")
					{
						extPort = inputRow[1].toInt(&data_ok);
						if (!data_ok) extPort = -1;
					}
					else if (inputRow[0] == "@ServerIP")
					{
						if (!localIP.setAddress(inputRow[1]))
							slot_serverMessenger("Error parsing conf file: incorrect server address!");
					}
					else continue;
				}
				else continue;
			}
			else break;
		}
		fileHandler->close();
	}
	QLineEdit * inputText = centralWidget()->findChild<QLineEdit*>("inputIntPort");
	inputText->setText(QString::number(intPort));
	inputText = centralWidget()->findChild<QLineEdit*>("inputExtPort");
	inputText->setText(QString::number(extPort));
	QComboBox *serverIP = centralWidget()->findChild<QComboBox*>("hostIPList");
	serverIP->clear();
	QList<QHostAddress> addrAval = QNetworkInterface::allAddresses();
	for (int i = 0; i < addrAval.count(); ++i)
	{
		QString addr = addrAval[i].toString();
		if (addr != "127.0.0.1" && isIPV4Address(addr))
		{
			serverIP->addItem(addr);
		}

	}
	if (serverIP->findText(localIP.toString()) != -1)
	{
		serverIP->setCurrentIndex(serverIP->findText(localIP.toString()));
	}
	else
	{
		localIP.setAddress(serverIP->itemText(0));
	}
	delete fileHandler;
}

void MainWindow::writeConfig()
{
	QString endl = "\r\n";
	#ifndef Q_WS_WIN
	endl = "\n";
	#endif
	fileHandler = new QFile("server.jpg");
	if (fileHandler->open(QFile::WriteOnly | QFile::Truncate))
	{
		fileHandler->write(QString("#Server configuration file" + endl).toStdString().c_str());
		fileHandler->write(QString("@ServerIP " + localIP.toString()
								   + endl).toStdString().c_str());
		fileHandler->write(QString("@LocalPort " + QString::number(intPort)
								   + endl).toStdString().c_str());
		fileHandler->write(QString("@ExternalPort " + QString::number(extPort)
								   + endl).toStdString().c_str());
		fileHandler->close();
	}
	else
	{
		QMessageBox::warning(this, "I/O error", "Cannot write server configuration file!",
							 QMessageBox::Ok, 0);
	}
	delete fileHandler;
	fileHandler = new QFile("client.jpg");
	if (fileHandler->open(QFile::WriteOnly | QFile::Truncate))
	{
		fileHandler->write(QString("#Client configuration file" + endl).toStdString().c_str());
		fileHandler->write(QString("@LocalPort 8888 #(Can be changed)" + endl).toStdString().c_str());
		fileHandler->write(QString("@ServerIP " + localIP.toString() + endl).toStdString().c_str());
		fileHandler->write(QString("@ExternalPort " + QString::number(extPort) + endl).toStdString().c_str());
		fileHandler->close();
	}
	else
	{
		QMessageBox::warning(this, "I/O error", "Cannot write client configuration file!",
							 QMessageBox::Ok, 0);
	}
	delete fileHandler;
}

void MainWindow::slot_serverMessenger(QString disp)
{

	QString endl = "\r\n";
	#ifndef Q_WS_WIN
	endl = "\n";
	#endif
	QString logString = QString(QDateTime::currentDateTime().toString("[dd.MM.yyyy hh:mm:ss.zzz] ")
								+ disp);
	QTextEdit *text = centralWidget()->findChild<QTextEdit*>(QString("logArea"));
	text->append(logString);
	fileHandler =  new QFile("server.log");
	if (fileHandler->open(QFile::WriteOnly | QFile::Append))
	{
		logString += endl;
		fileHandler->write(logString.toStdString().c_str());
		fileHandler->close();
	}
	else
	{
		QMessageBox::warning(this, "Logging error", "Cannot write to logfile!",
							 QMessageBox::Ok, 0);
	}
	delete fileHandler;
}

void MainWindow::slot_serverStarted(bool isStarted)
{
	isOnline = isStarted;
	centralWidget()->findChild<QPushButton*>(QString("buttonRun"))->setDisabled(isOnline);
	centralWidget()->findChild<QLineEdit*>(QString("inputExtPort"))->setDisabled(isOnline);
	centralWidget()->findChild<QLineEdit*>(QString("inputIntPort"))->setDisabled(isOnline);
	centralWidget()->findChild<QComboBox*>(QString("hostIPList"))->setDisabled(isOnline);
}


void MainWindow::on_buttonRun_clicked()
{
	QRegExp inputChecker("[1-9]\\d{0,4}");
	QLineEdit *inputExtPort = centralWidget()->findChild<QLineEdit*>(QString("inputExtPort"));
	QLineEdit *inputIntPort = centralWidget()->findChild<QLineEdit*>(QString("inputIntPort"));
	QComboBox *serverIP = centralWidget()->findChild<QComboBox*>(QString("hostIPList"));
	if (!(inputChecker.exactMatch(inputExtPort->text()) &&
		  inputChecker.exactMatch(inputIntPort->text())))
	{
		QMessageBox::critical(0,
							  "Invalid port(s) number",
							  "Port can only be a number 1 - 99999",
							  QMessageBox::Ok,
							  0);
		inputIntPort->clear();
		inputExtPort->clear();
		return;
	}
	extPort = inputExtPort->text().toInt();
	intPort = inputIntPort->text().toInt();
	localIP.setAddress(serverIP->currentText());
	writeConfig();
	emit signal_startServer(extPort, intPort, localIP);
}

void MainWindow::on_buttonStop_clicked()
{
	if (isOnline)
		emit signal_stopServer();
}

void MainWindow::on_buttonRestart_clicked()
{
	on_buttonStop_clicked();
	on_buttonRun_clicked();
}
bool MainWindow::isIPV4Address(QString address)
{
	QStringList listAddress = address.split(".",QString::SkipEmptyParts);
	if (listAddress.count() == 4)
	{
		for (int i = 0; i < 4; ++i)
		{
			bool ok = false;
			int a = QString(listAddress[i]).toInt(&ok);
			if (ok)
			{
				if (a >= (i > 0 ? 0 : 1) && a <= 255)
					continue;
			}
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

void MainWindow::on_actionRun_triggered()
{
	this->on_buttonRun_clicked();
}

void MainWindow::on_actionStop_triggered()
{
	this->on_buttonStop_clicked();
}

void MainWindow::on_actionRestart_triggered()
{
	this->on_buttonRestart_clicked();
}

void MainWindow::on_actionSaveCfg_triggered()
{
	writeConfig();
}

void MainWindow::on_actionLoad_triggered()
{
	this->on_buttonStop_clicked();
	loadConfig();
}

void MainWindow::on_actionQuit_triggered()
{
	this->on_buttonStop_clicked();
	emit signal_quit();
}

void MainWindow::on_actionHelp_triggered()
{
	QTextBrowser *help = new QTextBrowser();
	help->setFixedSize(640, 320);
	help->setWindowTitle("Server controller: help");
	help->setSource(*new QUrl("helpfile.html"));
	help->show();
}

void MainWindow::on_actionAbout_triggered()
{
	QTextBrowser *help = new QTextBrowser();
	help->setFixedSize(640, 320);
	help->setWindowTitle("Server controller: about");
	help->setSource(*new QUrl("about_us.html"));
	help->show();
}
