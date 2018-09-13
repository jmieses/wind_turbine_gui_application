#-------------------------------------------------
#
# Project created by QtCreator 2018-09-10T12:54:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = wind_turbine_gui_application
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    read.cpp \
    windspeed.cpp \
    turbine.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    read.h \
    windspeed.h \
    turbine.h \
    qcustomplot.h

FORMS    += mainwindow.ui

RESOURCES += \
    files.qrc
