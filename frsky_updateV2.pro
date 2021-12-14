# -------------------------------------------------
# Project created by QtCreator 2010-03-14T09:49:29
# -------------------------------------------------

TEMPLATE = app

CONFIG *= qt \
    thread \
    warn_on \
    static
# console

# QMAKE_CXXFLAGS_RELEASE = -O0 -g
# QMAKE_LFLAGS_RELEASE = -O0 -g

#force 32bit binaries even on 64bit systems
# QMAKE_CXXFLAGS -= -m64
# QMAKE_LFLAGS -= -m64
# QMAKE_CXXFLAGS += -m32
# QMAKE_LFLAGS += -m32
# LIBS = -L/usr/lib

unix:DEFINES = _TTY_POSIX_
win32:DEFINES = _TTY_WIN_

TARGET = frsky_update_dft

DEPENDPATH *= .
INCLUDEPATH += .

win32:CONFIG *= qextserialport-library
include(qextserialport/src/qextserialport.pri)

SOURCES += \
    common.c \
    crc16.cpp \
    frskyupdate.cpp \
    main.cpp \
    ymodem_host.c

unix:SOURCES += \
    PortListener.cpp

HEADERS += \
    common.h \
    crc16.h \
    frskyupdate.h \
    ymodem_host.h

unix:HEADERS += \
    frsky_structs.h \
    PortListener.h

FORMS += \
    frskyupdate.ui

RC_FILE = icon.rc

