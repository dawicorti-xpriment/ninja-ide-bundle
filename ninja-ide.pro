TEMPLATE = app
TARGET = dist/Ninja-IDE
DEPENDPATH += .
OBJECTS_DIR = ./build
INCLUDEPATH += ./deps/Python-2.7.6 ./deps/Python-2.7.6/Include
LIBS += -L./deps/Python-2.7.6 -lpython2.7

NINJA_IDE_FILES.files = ./deps/ninja-ide/ninja_ide
NINJA_IDE_FILES.path = Contents/Resources

PYTHON_FILES.files = ./deps/Python-2.7.6
PYTHON_FILES.path = Contents/Resources

QMAKE_BUNDLE_DATA += PYTHON_FILES NINJA_IDE_FILES

# Input
SOURCES += src/main.cc

