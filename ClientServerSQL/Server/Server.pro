TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpq

SOURCES += main.cpp \
    ../bad_cssql_exception.cpp \
    server.cpp \
    ../cJSON.c \
    ../workwithnetwork.cpp \
    ../postgres.cpp \
    ../cash.cpp \
    ../workwitstorage.cpp

HEADERS += \
    server.h \
    ../bad_cssql_exception.h \
    ../cJSON.h \
    ../workwithnetwork.h \
    ../postgres.h \
    ../cash.h \
    ../workwithstorage.h
