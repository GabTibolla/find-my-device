QT += core gui webkit webkitwidgets
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWebView
TEMPLATE = app

SOURCES += \
    database.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    database.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

