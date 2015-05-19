! include(../common.pri) {
    error("Common project file not found")
}

TEMPLATE = lib
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#LIBS += -lfl -LC:/GnuWin32/lib
#INCLUDEPATH += C:/GnuWin32/include

SOURCES += \
    tsplib.yy.c

HEADERS +=

DISTFILES += \
    tsplib.l
