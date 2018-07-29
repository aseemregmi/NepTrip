QT += core gui
QT += qml quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NepTrip
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
    search.h

DISTFILES += \
    map.qml

RESOURCES += \
    resource.qrc
