#-------------------------------------------------
#
# Project created by QtCreator 2016-01-23T19:51:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = olentoStatistics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    olentotable.cpp \
    kappale.cpp \
    statistics.cpp

HEADERS  += mainwindow.h \
    olentotable.h \
    kappale.h \
    statistics.h

FORMS    += mainwindow.ui

DISTFILES += \
    shapeTable.txt
