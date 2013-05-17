TEMPLATE = app
CONFIG += console
CONFIG -= qt

macx {
    CONFIG_PLATFORM_PATH  = mac
}

win32 {
    CONFIG_PLATFORM_PATH  = win32
}

unix:!macx {
    CONFIG_PLATFORM_PATH  = unix
}


INCLUDEPATH += "$${PWD}/library/sfml/$${CONFIG_PLATFORM_PATH}/include"
INCLUDEPATH += "$${PWD}/library/sndfile/$${CONFIG_PLATFORM_PATH}/include"

SOURCES += main.cpp \
    Engine.cpp \
    Util.cpp

OTHER_FILES += \
    build.sh \
    build/build.sh \
    build/clean.sh \
    build/rebuild.sh \
    CMakeLists.txt \
    .gitignore \
    build/cmake/modules/FindSFML.cmake \
    ResourcePath.mm \
    js/robot1.js \
    js/robot2.js

HEADERS += \
    ResourcePath.hpp \
    Engine.h \
    Util.h
