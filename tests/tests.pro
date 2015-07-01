! include(../common.pri) {
    error("Common project file not found")
}

include(gtest.pri)

INCLUDEPATH += ../parser/ ../common/

LIBS += -L$$OUT_PWD/../parser/$$LOCATION/ -lparser -L$$OUT_PWD/../common/$$LOCATION/ -lcommon

SOURCES += \
    parsertest.cpp
