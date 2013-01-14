#-------------------------------------------------
#
# Project created by QtCreator 2012-11-30T19:52:26
#
#-------------------------------------------------

QT  += core network
QT  -= gui

TARGET = Client
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp\
	client.cpp \
    stdafx.cpp \
    cipherer.cpp

HEADERS  += client.h \
    stdafx.h \
    cipherer.h \
    ../Server/debugmode.h
win32: LIBS += -lws2_32
