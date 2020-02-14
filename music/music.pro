#-------------------------------------------------
#
# Project created by QtCreator 2019-12-07T05:46:28
#
#-------------------------------------------------

QT       += core gui

QT += multimedia
QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = music
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sign_in.cpp

HEADERS  += mainwindow.h \
    sign_in.h

FORMS    += mainwindow.ui \
    sign_in.ui

RESOURCES += \
    image.qrc

DISTFILES += \
    ../QTtest/QT图片/img/2.jpg \
    ../QTtest/QT图片/img/0.jpg \
    ../QTtest/QT图片/img/1.jpg \
    ../QTtest/QT图片/img/5.jpg \
    ../QTtest/QT图片/img/3.jpg \
    ../QTtest/QT图片/img/4.jpg \
    ../QTtest/QT图片/img/banner.jpg \
    ../QTtest/QT图片/img/music-back.png

