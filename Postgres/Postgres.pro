TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpq

SOURCES += main.cpp \
    ../ClientServerSQL/bad_cssql_exception.cpp \
    postgres.cpp

HEADERS += \
    ../ClientServerSQL/bad_cssql_exception.h \
    postgres.h
