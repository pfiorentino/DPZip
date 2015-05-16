TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    filepool.cpp \

HEADERS += \
    filepool.h \

QMAKE_CXXFLAGS += -std=c++0x
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

