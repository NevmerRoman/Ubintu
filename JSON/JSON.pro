TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../ClientServerSQL/cJSON.c

HEADERS += \
    ../ClientServerSQL/cJSON.h
