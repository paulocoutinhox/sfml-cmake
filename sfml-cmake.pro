TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    sf_v8.cpp \
    v8wrap.cpp

OTHER_FILES += \
    build.sh \
    build/build.sh \
    build/clean.sh \
    CMakeLists.txt \
    .gitignore \
    build/cmake/modules/FindSndfile.cmake \
    build/cmake/modules/FindSFML.cmake \
    build/cmake/modules/FindGLEW.cmake

HEADERS += \
    v8wrap.h \
    sf_v8.h

