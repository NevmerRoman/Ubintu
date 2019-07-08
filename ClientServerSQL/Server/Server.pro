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
    ../workwitstorage.cpp \
    ../cashe.cpp \
    ../log.cpp

HEADERS += \
    server.h \
    ../bad_cssql_exception.h \
    ../cJSON.h \
    ../workwithnetwork.h \
    ../postgres.h \
    ../workwithstorage.h \
    ../cashe.h \
    ../log.h
