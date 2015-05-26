TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
#    filepool.cpp \
    zipper.cpp \
#    zippedbufferpool.cpp \
    writer.cpp \
    dpzip.cpp \
    datapool.cpp \
    reader.cpp \
    unzipper.cpp \
    ucfilewriter.cpp \
    databuffer.cpp

HEADERS += \
#    filepool.h \
    zipper.h \
#    zippedbufferpool.h \
    writer.h \
    dpzip.h \
    datapool.h \
    reader.h \
    unzipper.h \
    ucfilewriter.h \
    databuffer.h

QMAKE_CXXFLAGS += -std=c++0x
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

DISTFILES += \
    banner

