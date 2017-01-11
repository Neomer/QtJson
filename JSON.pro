QT += core
QT -= gui

TARGET = JSON
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Parser.cpp \
    Document.cpp \
    Value.cpp \
    Element.cpp

HEADERS += \
    Parser.h \
    Document.h \
    Value.h \
    Element.h

