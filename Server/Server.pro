#-------------------------------------------------

QT       += core gui network

TARGET = Server
TEMPLATE = app

SOURCES += main.cpp\
	server.cpp \
    mainwindow.cpp \
    cipherer.cpp \
    stdafx.cpp

HEADERS  += server.h \
    mainwindow.h \
    cipherer.h \
    stdafx.h \
    debugmode.h

FORMS += mainwindow.ui

