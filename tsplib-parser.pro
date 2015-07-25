! include(common.pri) {
    error("Common project file not found")
}

TEMPLATE = subdirs

SUBDIRS = common \
          parser \
          standalone \
          tests

CONFIG += ordered
