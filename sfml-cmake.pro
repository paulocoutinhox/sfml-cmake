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

SOURCES += main.cpp \
    sf_v8.cpp \
    v8wrap.cpp \
    JSCharacter.cpp \
    Character.cpp

OTHER_FILES += \
    build.sh \
    build/build.sh \
    build/clean.sh \
    CMakeLists.txt \
    .gitignore \
    build/cmake/modules/FindSFML.cmake \
    ResourcePath.mm \
    js/robot1.js

HEADERS += \
    v8wrap.h \
    sf_v8.h \
    ResourcePath.hpp \
    JSCharacter.h \
    Character.h

INCLUDEPATH += "$${PWD}/library/sfml/$${CONFIG_PLATFORM_PATH}/include"
INCLUDEPATH += "$${PWD}/library/v8/$${CONFIG_PLATFORM_PATH}/include"
INCLUDEPATH += "$${PWD}/library/sndfile/$${CONFIG_PLATFORM_PATH}/include"
