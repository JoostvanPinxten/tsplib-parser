! include(../common.pri) {
    error("Common project file not found")
}

bison.name = Bison ${QMAKE_FILE_IN}
bison.input = BISONSOURCES
bison.output = ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}_parser.cpp
bison.commands = bison -d -o ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}_parser.cpp ${QMAKE_FILE_IN}
bison.CONFIG += target_predeps
bison.variable_out = GENERATED_SOURCES
silent:bison.commands = @echo Bison ${QMAKE_FILE_IN} && $$bison.commands
QMAKE_EXTRA_COMPILERS += bison
bison_header.input = BISONSOURCES
bison_header.output = ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}.parser.hpp
bison_header.commands = bison -d -o ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}.parser.cpp ${QMAKE_FILE_IN}
bison_header.CONFIG += target_predeps no_link
silent:bison_header.commands = @echo Bison ${QMAKE_FILE_IN} && $$bison.commands
QMAKE_EXTRA_COMPILERS += bison_header

flex.name = Flex ${QMAKE_FILE_IN}
flex.input = FLEXSOURCES
flex.output = ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}_lexer.cpp
flex.commands = flex -o ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}_lexer.cpp ${QMAKE_FILE_IN}
flex.CONFIG += target_predeps
flex.variable_out = GENERATED_SOURCES
silent:flex.commands = @echo Lex ${QMAKE_FILE_IN} && $$flex.commands
QMAKE_EXTRA_COMPILERS += flex

FLEXSOURCES += \
    tsplib.l

BISONSOURCES += \
    tsplib.y

SOURCES += \
    tsplib_driver.cpp
#    tsplib_parser.cpp \
#    tsplib_lexer.cpp

HEADERS += \
    tsplib_driver.h
#    tsplib_parser.hpp

TEMPLATE = lib

CONFIG -= app_bundle
CONFIG -= qt

LIBS +=

CONFIG += debug_and_release

#YACCSOURCES += \
#    tsplib.y
