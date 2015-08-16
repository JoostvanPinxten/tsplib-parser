UI_DIR = uics
MOC_DIR = mocs
OBJECTS_DIR = objs

INCLUDEPATH += $$PWD/. $$PWD/.. $$PWD/../common

CONFIG += c++11
CONFIG -= qt

win32:CONFIG(release, debug|release) {
    LOCATION = /release
} else {
    LOCATION = /debug
}

unix: LOCATION =

