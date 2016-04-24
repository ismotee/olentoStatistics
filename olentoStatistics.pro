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
    kappalewidget.cpp \
    kappaletablewidget.cpp \
    kappale.cpp \
    glwidget.cpp \
    shader.cpp

HEADERS  += mainwindow.h \
    olentotable.h \
    kappale.h \
    kappalewidget.h \
    kappaletablewidget.h \
    glwidget.h \
    shader.hpp

FORMS    += mainwindow.ui \
    kappalewidget.ui \
    kappaletablewidget.ui

DISTFILES += \
    shapeTable.txt \
    SimpleTransform.fragmentshader \
    SimpleTransform.vertexshader
