#-------------------------------------------------
#
# Project created by QtCreator 2019-12-08T19:32:42
#
#-------------------------------------------------

QT       += core gui
QT +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homewo
TEMPLATE = app


SOURCES += main.cpp\
        homewo.cpp \
    webdialog.cpp \
    web2dialog.cpp \
    stopdialog.cpp

HEADERS  += homewo.h \
    webdialog.h \
    web2dialog.h \
    stopdialog.h

FORMS    += homewo.ui \
    webdialog.ui \
    web2dialog.ui \
    stopdialog.ui

RESOURCES += \
    res.qrc
