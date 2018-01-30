QT += core
QT -= gui
QT += network

TARGET = Fusion-QtWebApp

CONFIG += c++11 console
CONFIG += console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += src/main.cpp \
    src/requestmapper.cpp \
    src/testcontroller.cpp \
    src/htmltestcontroller.cpp \
    src/templatecontrollerexample.cpp \
    src/musicappcontroller.cpp

HEADERS += \
    src/requestmapper.h \
    src/testcontroller.h \
    src/htmltestcontroller.h \
    src/templatecontrollerexample.h \
    src/musicappcontroller.h


OTHER_FILES += etc/webapp1.ini

include(QtWebApp/httpserver/httpserver.pri)
include(QtWebApp/templateengine/templateengine.pri)

