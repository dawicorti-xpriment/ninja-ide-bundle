TEMPLATE = app
TARGET = dist/Ninja-IDE
DEPENDPATH += .
OBJECTS_DIR = ./build
INCLUDEPATH += ./deps/Python-2.7.6 ./deps/Python-2.7.6/Include
LIBS += -L./deps/Python-2.7.6 -lpython2.7
CONFIG += app_bundle


# Input
SOURCES += src/main.cc
