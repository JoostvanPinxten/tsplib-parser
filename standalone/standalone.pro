! include(../common.pri) {
    error("Common project file not found")
}

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp
HEADERS +=

LIBS +=
