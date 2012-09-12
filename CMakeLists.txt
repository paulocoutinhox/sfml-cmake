# versao minima requerida
cmake_minimum_required(VERSION 2.8)

# variaveis do projeto
set(PROJECT_NAME "sfml-project")

set(
    GAME_ALL_SOURCES
    ../main.cpp
)

set(TARGET_SYSTEM "mac")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/cmake/modules")

set(SFML_ROOT "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")

# nome do projeto
project(${PROJECT_NAME})

# compila
add_executable(
    ${PROJECT_NAME}
    MACOSX_BUNDLE
    ${GAME_ALL_SOURCES}
)

# biblioteca SFML
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

include_directories(
    ${SFML_INCLUDE_DIR}
)

link_directories(
    ${SFML_LIBRARY_DIR}
)

# link de bibliotecas
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

# propriedade dos arquivos
SET_SOURCE_FILES_PROPERTIES(
    ../resources/*
    PROPERTIES
    MACOSX_PACKAGE_LOCATION Resources
)
