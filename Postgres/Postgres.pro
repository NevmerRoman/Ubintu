TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpq

SOURCES += main.cpp \
    workwithsql.cpp \
    ../ClientServerSQL/bad_cssql_exception.cpp

HEADERS += \
    workwithsql.h \
    ../ClientServerSQL/bad_cssql_exception.h
