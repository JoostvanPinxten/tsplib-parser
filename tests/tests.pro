! include(../common.pri) {
    error("Common project file not found")
}

include(gtest.pri)

INCLUDEPATH += ../parser/
LIBS += -L$$OUT_PWD/../parser/debug/ -lparser

SOURCES += lexertest.cpp
