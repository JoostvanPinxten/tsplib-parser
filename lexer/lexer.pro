! include(../common.pri) {
    error("Common project file not found")
}

TEMPLATE = lib
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=

HEADERS +=

DISTFILES += \
    tsplib.l
