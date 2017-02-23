#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T21:59:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

VERSION = 1.0.0
QMAKE_TARGET_COMPANY = KNT Company
QMAKE_TARGET_PRODUCT = Stationers shop
QMAKE_TARGET_COPYRIGHT = Harkovenko Simonenko Korniychuk


TARGET = Kurs1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    prod.cpp \
    add.cpp \
    postavka.cpp \
    constants.cpp

HEADERS  += mainwindow.h \
    prod.h \
    add.h \
    postavka.h \
    constants.h

FORMS    += mainwindow.ui \
    prod.ui \
    add.ui \
    postavka.ui

RESOURCES +=
