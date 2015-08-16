! include(../common.pri) {
    error("Common project file not found")
}

include(gtest.pri)

INCLUDEPATH += ../parser/ ../common/

LIBS += -L$$OUT_PWD/../parser/$$LOCATION -lparser -L$$OUT_PWD/../common/$$LOCATION -lcommon -lpthread

SOURCES += \
    parsertest.cpp \
    tourtests.cpp \
    tsptests.cpp \
    gtsptests.cpp
