# versao minima requerida
cmake_minimum_required(VERSION 2.8)

# variaveis do projeto
set(PROJECT_NAME "sfml-project")

set(
    GAME_ALL_SOURCES
    ../main.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/cmake/modules")

# nome do projeto
project(${PROJECT_NAME})

# biblioteca SFML
find_package(SFML REQUIRED system window graphics network audio)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

include_directories(
    ${CMAKE_SOURCE_DIR}/library/sfml/mac/include
)

#link_directories(
#    ${CMAKE_CURRENT_SOURCE_DIR}/../library/sfml/mac/lib
#)

# compila
ADD_EXECUTABLE(
    ${PROJECT_NAME}
    MACOSX_BUNDLE
    ${GAME_ALL_SOURCES}
)

# link com as bibliotecas
#target_link_libraries(
#    sfml-main
#    sfml-system
#    sfml-window
#)

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

#install(TARGETS sfml-cmake DESTINATION bin)
