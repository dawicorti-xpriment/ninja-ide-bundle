TEMPLATE = app
TARGET = dist/Ninja-IDE
DEPENDPATH += .
OBJECTS_DIR = ./build
INCLUDEPATH += ./deps/Python-2.7.6 ./deps/Python-2.7.6/Include
LIBS += -L./deps/Python-2.7.6 -lpython2.7

APP_QML_FILES.files = ./deps/Python-2.7.6
APP_QML_FILES.path = Contents/Resources
QMAKE_BUNDLE_DATA += APP_QML_FILES

# Input
SOURCES += src/main.cc
