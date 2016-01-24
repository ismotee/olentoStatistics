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
<<<<<<< HEAD
    kappalewidget.cpp \
    kappaletablewidget.cpp
=======
    statistics.cpp
>>>>>>> cf923c9699eeb43d0578769b6cf7185aca1273d0

HEADERS  += mainwindow.h \
    olentotable.h \
    kappale.h \
<<<<<<< HEAD
    kappalewidget.h \
    kappaletablewidget.h
=======
    statistics.h
>>>>>>> cf923c9699eeb43d0578769b6cf7185aca1273d0

FORMS    += mainwindow.ui \
    kappalewidget.ui \
    kappaletablewidget.ui

DISTFILES += \
    shapeTable.txt
