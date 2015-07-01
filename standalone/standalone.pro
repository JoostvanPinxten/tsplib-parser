! include(../common.pri) {
    error("Common project file not found")
}
INCLUDEPATH += ../common/ ../parser/

LIBS += -L$$OUT_PWD/../common/$$LOCATION/ -lcommon -L$$OUT_PWD/../parser/$$LOCATION/ -lparser

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp
HEADERS +=

LIBS +=
