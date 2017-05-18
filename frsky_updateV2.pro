# -------------------------------------------------
# Project created by QtCreator 2010-03-14T09:49:29
# -------------------------------------------------
OBJECTS_DIR = obj
MOC_DIR = moc
UI_DIR = uic
CONFIG += qt \
    thread \
    warn_on \
    static
# console
DEPENDPATH += .
INCLUDEPATH += ./qserial
QMAKE_LIBDIR += ./qserial
CONFIG(debug, debug|release):LIBS += -lqextserialportd
else:LIBS += -lqextserialport
unix:DEFINES = _TTY_POSIX_
win32:DEFINES = _TTY_WIN_
TARGET = frsky_update_dft
TEMPLATE = app
SOURCES += main.cpp \
    frskyupdate.cpp \
    ymodem_host.c \
    common.c \
    crc16.cpp
HEADERS += frskyupdate.h \
    crc16.h \
    common.h \
    ymodem_host.h
FORMS += frskyupdate.ui
RC_FILE = icon.rc
