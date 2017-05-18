#-------------------------------------------------
#
# Project created by QtCreator 2011-11-06T21:37:41
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS_RELEASE = -O0 -g
QMAKE_LFLAGS_RELEASE = -O0 -g
contains(QT_VERSION, ^5\\..*\\..*): QT += widgets

TARGET = uartassistant
TEMPLATE = app

include(../../src/qextserialport.pri)

SOURCES += main.cpp\
        dialog.cpp\
        hled.cpp

HEADERS  += dialog.h \
            hled.h

FORMS    += dialog.ui
