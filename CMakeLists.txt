# versao minima requerida
cmake_minimum_required(VERSION 2.8)

# variaveis do projeto
set(PROJECT_NAME "sfml-project")

set(
    GAME_ALL_SOURCES
    ../main.cpp
)

if(APPLE)
    set(TARGET_SYSTEM "mac")
elseif(WIN32)
    set(TARGET_SYSTEM "win32")
else()
    set(TARGET_SYSTEM "linux")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/cmake/modules")

set(SFML_ROOT "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")

# nome do projeto
project(${PROJECT_NAME})

# biblioteca SFML
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

include_directories(
    ${SFML_INCLUDE_DIR}
)

set_source_files_properties(${SFML_LIBRARIES} PROPERTIES MACOSX_PACKAGE_LOCATION Frameworks)

# compila
add_executable(
    ${PROJECT_NAME}
    MACOSX_BUNDLE
    ${GAME_ALL_SOURCES}
    ${SFML_LIBRARIES}
)

# link de bibliotecas
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

# propriedade dos arquivos
set_source_files_properties(
    ../resources/*
    PROPERTIES
    MACOSX_PACKAGE_LOCATION Resources
)
