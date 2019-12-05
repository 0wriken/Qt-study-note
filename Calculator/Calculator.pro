#-------------------------------------------------
#
# Project created by QtCreator 2019-12-02T04:33:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    quit.cpp \
    sty_dialog.cpp \
    lable_b.cpp \
    pushbo_btn.cpp \
    function.cpp \
    pic_show.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    quit.h \
    sty_dialog.h \
    lable_b.h \
    pushbo_btn.h \
    function.h \
    pic_show.h

FORMS    += mainwindow.ui \
    dialog.ui \
    quit.ui \
    sty_dialog.ui \
    lable_b.ui \
    pushbo_btn.ui \
    function.ui \
    pic_show.ui
