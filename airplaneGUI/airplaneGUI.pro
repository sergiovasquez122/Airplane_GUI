#-------------------------------------------------
#
# Project created by QtCreator 2018-06-09T10:45:58
#
#-------------------------------------------------

QT       += core gui
QT       += webengine webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = airplaneGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    airline.cpp \
    airplane.cpp \
    bellmanford.cpp \
    directededge.cpp \
    dijsktra.cpp \
    graph.cpp \
    graphbuilder.cpp \
    breadthfirstsearch.cpp \
    latlng.cpp

HEADERS  += mainwindow.h \
    airline.h \
    airplane.h \
    bellmanford.h \
    directededge.h \
    dijsktra.h \
    vertex.h \
    graph.h \
    graphbuilder.h \
    breadthfirstsearch.h \
    latlng.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
