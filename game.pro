#-------------------------------------------------
#
# Project created by QtCreator 2014-02-19T01:00:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    grid.cpp \
    basicitem.cpp

HEADERS  += mainwindow.h \
    grid.h \
    basicitem.h

FORMS    += mainwindow.ui

CONFIG += c++11
