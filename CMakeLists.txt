# versao minima requerida
cmake_minimum_required(VERSION 2.8)

# variaveis do projeto
set(PROJECT_NAME "sfml-project")

set(
    GAME_ALL_SOURCES
    ../main.cpp
)

# nome do projeto
project(sfml-cmake)

# compila
ADD_EXECUTABLE(
    sfml-cmake
    MACOSX_BUNDLE
    ${GAME_ALL_SOURCES}
)

#SET_SOURCE_FILES_PROPERTIES(
    # arquivos
#    PROPERTIES
#    MACOSX_PACKAGE_LOCATION MacOSX
#)

SET_SOURCE_FILES_PROPERTIES(
    ../resources/*
    PROPERTIES
    MACOSX_PACKAGE_LOCATION Resources
)

install(TARGETS sfml-cmake DESTINATION bin)
