! include(../common.pri) {
    error("Common project file not found")
}

include(gtest.pri)

SOURCES += lexertest.cpp
