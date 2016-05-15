#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T21:36:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamepage.cpp \
    item.cpp \
    showresult.cpp \
    ready.cpp

HEADERS  += mainwindow.h \
    gamepage.h \
    item.h \
    showresult.h \
    ready.h

FORMS    += mainwindow.ui \
    gamepage.ui \
    showresult.ui \
    ready.ui

RESOURCES += \
    source.qrc
LIBS += -framework AppKit
LIBS += -framework CoreAudio
LIBS += -framework AudioToolbox
