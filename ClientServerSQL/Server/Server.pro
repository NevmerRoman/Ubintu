TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../bad_cssql_exception.cpp \
    ../createsocket.cpp \
    ../sendrecv.cpp \
    server.cpp \
    ../cJSON.c

HEADERS += \
    server.h \
    ../bad_cssql_exception.h \
    ../createsocket.h \
    ../sendrecv.h \
    ../cJSON.h
