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
    nextpage.cpp \
    gamepage.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    nextpage.h \
    gamepage.h \
    item.h

FORMS    += mainwindow.ui \
    nextpage.ui \
    gamepage.ui

RESOURCES += \
    source.qrc
LIBS += -framework AppKit
LIBS += -framework CoreAudio
LIBS += -framework AudioToolbox
