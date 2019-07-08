TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    client.cpp \
    ../bad_cssql_exception.cpp \
    ../cJSON.c \
    ../workwithnetwork.cpp \
    ../log.cpp

HEADERS += \
    client.h \
    ../bad_cssql_exception.h \
    ../cJSON.h \
    ../workwithnetwork.h \
    ../log.h
