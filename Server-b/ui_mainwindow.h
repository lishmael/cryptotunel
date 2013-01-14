/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jan 10 14:15:05 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRun;
    QAction *actionStop;
    QAction *actionRestart;
    QAction *actionSaveCfg;
    QAction *actionLoad;
    QAction *actionQuit;
    QAction *actionHelp;
    QAction *actionAbout;
    QWidget *centralwidget;
    QPushButton *buttonRun;
    QTextBrowser *logArea;
    QLineEdit *inputIntPort;
    QLineEdit *inputExtPort;
    QPushButton *buttonStop;
    QPushButton *buttonRestart;
    QLabel *labelExternalPort;
    QLabel *labelInternalPort;
    QComboBox *hostIPList;
    QLabel *labelServerIP;
    QMenuBar *menuBar;
    QMenu *menuMain;
    QMenu *menuService;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(790, 508);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QString::fromUtf8("actionRestart"));
        actionSaveCfg = new QAction(MainWindow);
        actionSaveCfg->setObjectName(QString::fromUtf8("actionSaveCfg"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        buttonRun = new QPushButton(centralwidget);
        buttonRun->setObjectName(QString::fromUtf8("buttonRun"));
        buttonRun->setGeometry(QRect(280, 20, 141, 81));
        logArea = new QTextBrowser(centralwidget);
        logArea->setObjectName(QString::fromUtf8("logArea"));
        logArea->setGeometry(QRect(10, 120, 771, 361));
        inputIntPort = new QLineEdit(centralwidget);
        inputIntPort->setObjectName(QString::fromUtf8("inputIntPort"));
        inputIntPort->setGeometry(QRect(140, 50, 121, 21));
        QFont font;
        font.setPointSize(8);
        inputIntPort->setFont(font);
        inputIntPort->setMaxLength(5);
        inputIntPort->setAlignment(Qt::AlignCenter);
        inputExtPort = new QLineEdit(centralwidget);
        inputExtPort->setObjectName(QString::fromUtf8("inputExtPort"));
        inputExtPort->setGeometry(QRect(140, 20, 121, 21));
        inputExtPort->setFont(font);
        inputExtPort->setMaxLength(5);
        inputExtPort->setAlignment(Qt::AlignCenter);
        buttonStop = new QPushButton(centralwidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setGeometry(QRect(460, 20, 141, 81));
        buttonRestart = new QPushButton(centralwidget);
        buttonRestart->setObjectName(QString::fromUtf8("buttonRestart"));
        buttonRestart->setGeometry(QRect(640, 20, 141, 81));
        labelExternalPort = new QLabel(centralwidget);
        labelExternalPort->setObjectName(QString::fromUtf8("labelExternalPort"));
        labelExternalPort->setGeometry(QRect(10, 21, 141, 20));
        labelInternalPort = new QLabel(centralwidget);
        labelInternalPort->setObjectName(QString::fromUtf8("labelInternalPort"));
        labelInternalPort->setGeometry(QRect(10, 51, 141, 20));
        hostIPList = new QComboBox(centralwidget);
        hostIPList->setObjectName(QString::fromUtf8("hostIPList"));
        hostIPList->setGeometry(QRect(140, 80, 121, 20));
        hostIPList->setMinimumSize(QSize(121, 20));
        hostIPList->setMaximumSize(QSize(121, 20));
        hostIPList->setMaxVisibleItems(15);
        hostIPList->setInsertPolicy(QComboBox::InsertAlphabetically);
        labelServerIP = new QLabel(centralwidget);
        labelServerIP->setObjectName(QString::fromUtf8("labelServerIP"));
        labelServerIP->setGeometry(QRect(10, 81, 131, 20));
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 790, 25));
        menuMain = new QMenu(menuBar);
        menuMain->setObjectName(QString::fromUtf8("menuMain"));
        menuService = new QMenu(menuBar);
        menuService->setObjectName(QString::fromUtf8("menuService"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMain->menuAction());
        menuBar->addAction(menuService->menuAction());
        menuMain->addAction(actionRun);
        menuMain->addAction(actionStop);
        menuMain->addAction(actionRestart);
        menuMain->addAction(actionSaveCfg);
        menuMain->addAction(actionLoad);
        menuMain->addAction(actionQuit);
        menuService->addAction(actionHelp);
        menuService->addSeparator();
        menuService->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Server Controller v1.0", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "\320\227\321\203\320\277\320\270\320\275\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionRestart->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\321\202\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionSaveCfg->setText(QApplication::translate("MainWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\275\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\275\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\274\320\276\320\263\320\260", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\321\203", 0, QApplication::UnicodeUTF8));
        buttonRun->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", 0, QApplication::UnicodeUTF8));
        inputIntPort->setInputMask(QString());
        inputExtPort->setInputMask(QString());
        inputExtPort->setText(QString());
        buttonStop->setText(QApplication::translate("MainWindow", "\320\227\321\203\320\277\320\270\320\275\320\272\320\260", 0, QApplication::UnicodeUTF8));
        buttonRestart->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\320\272", 0, QApplication::UnicodeUTF8));
        labelExternalPort->setText(QApplication::translate("MainWindow", "\320\227\320\276\320\262\320\275\321\226\321\210\320\275\321\226\320\271 \320\277\320\276\321\200\321\202:", 0, QApplication::UnicodeUTF8));
        labelInternalPort->setText(QApplication::translate("MainWindow", "\320\222\320\275\321\203\321\202\321\200\321\226\321\210\320\275\321\226\320\271 \320\277\320\276\321\200\321\202:", 0, QApplication::UnicodeUTF8));
        labelServerIP->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201\320\260 \321\201\320\265\321\200\320\262\320\265\321\200\320\260:", 0, QApplication::UnicodeUTF8));
        menuMain->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0, QApplication::UnicodeUTF8));
        menuService->setTitle(QApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\321\226\321\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
