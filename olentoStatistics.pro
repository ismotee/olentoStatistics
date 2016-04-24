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
<<<<<<< HEAD
    glwidget.cpp
=======
    glwidget.cpp \
    dobject.cpp \
    material.cpp \
    oLoader.cpp
>>>>>>> 47aae284cfc407900ccd90eaffa24ac0650a411d

HEADERS  += mainwindow.h \
    olentotable.h \
    kappale.h \
    kappalewidget.h \
    kappaletablewidget.h \
<<<<<<< HEAD
    glwidget.h
=======
    glwidget.h \
    dClock.h \
    dFace.h \
    dobject.h \
    material.h \
    oDirectory.h \
    oLoader.h \
    oMesh.h \
    oMeshBundle.h \
    oModificators.h
>>>>>>> 47aae284cfc407900ccd90eaffa24ac0650a411d

FORMS    += mainwindow.ui \
    kappalewidget.ui \
    kappaletablewidget.ui

DISTFILES += \
    shapeTable.txt \
    StandardShading.fragmentshader \
    StandardShading.vertexshader
