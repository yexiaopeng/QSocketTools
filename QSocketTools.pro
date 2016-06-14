#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T16:55:23
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSocketTools
TEMPLATE = app


SOURCES += main.cpp\
        qsockettools.cpp \
    protocol/source/ntprotocol.cpp \
    msgdecoder/ntmsgdecoder.cpp


HEADERS  += qsockettools.h \
    c_type.h \
    protocol/include/ntprotocol.h \
     NTMsgDecoder.h \
    msgdecoder/ntmsgdecoder.h

FORMS    += qsockettools.ui
