! include(../common.pri) {
    error("Common project file not found")
}

HEADERS += \
    tsp.h \
    tsplibinstance.h \
    basetsplibinstance.h

TEMPLATE = lib

SOURCES += \
    tsplibinstance.cpp \
    basetsplibinstance.cpp
