TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    filepool.cpp \
    zipper.cpp \
    zippedbuffer.cpp \
    zippedbufferpool.cpp \
    writer.cpp \
    dpzip.cpp

HEADERS += \
    filepool.h \
    zipper.h \
    zippedbuffer.h \
    zippedbufferpool.h \
    writer.h \
    dpzip.h

QMAKE_CXXFLAGS += -std=c++0x
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

