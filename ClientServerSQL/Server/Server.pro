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
    ../log.cpp \
    cashe.cpp \
    postgres.cpp \
    storage.cpp

HEADERS += \
    server.h \
    ../bad_cssql_exception.h \
    ../cJSON.h \
    ../workwithnetwork.h \
    ../log.h \
    cashe.h \
    postgres.h \
    workwithstorage.h \
    storage.h \
    storage.h
