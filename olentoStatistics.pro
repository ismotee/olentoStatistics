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
    dobject.cpp \
    material.cpp \
    oLoader.cpp \
    window.cpp \
    oMesh.cpp \
    oMeshBundle.cpp \
    oModificators.cpp \
    oDirectory.cpp

HEADERS  += mainwindow.h \
    olentotable.h \
    kappale.h \
    kappalewidget.h \
    kappaletablewidget.h \
    glwidget.h \
    dClock.h \
    dFace.h \
    dobject.h \
    material.h \
    oDirectory.h \
    oLoader.h \
    window.h \
    oMesh.h \
    oMeshBundle.h \
    oModificators.h

FORMS    += mainwindow.ui \
    kappalewidget.ui \
    kappaletablewidget.ui

DISTFILES += \
    shapeTable.txt \
    SimpleTransform.fragmentshader \
    SimpleTransform.vertexshader
