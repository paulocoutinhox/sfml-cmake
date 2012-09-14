# versao minima requerida
cmake_minimum_required(VERSION 2.8)

# variaveis do projeto
set(PROJECT_NAME "sfml-project")

set(
    GAME_ALL_SOURCES
    ../main.cpp
    ../sf_v8.cpp
    ../v8wrap.cpp
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
set(SNDFILE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/sndfile/${TARGET_SYSTEM}/include")
set(SNDFILE_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/sndfile/${TARGET_SYSTEM}/lib")
set(V8_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/v8/${TARGET_SYSTEM}/include")
set(V8_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/v8/${TARGET_SYSTEM}/lib")

# nome do projeto
project(${PROJECT_NAME})

# biblioteca SFML
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

include_directories(
    ${SFML_INCLUDE_DIR}
)

# biblioteca SNDFILE
find_package(SNDFILE REQUIRED)

include_directories(
    ${SNDFILE_INCLUDE_DIR}
)

# biblioteca V8
include_directories(
    ${V8_INCLUDE_DIR}
)

find_library(V8_LIBRARIES v8 ${V8_LIBRARY_DIR})

# compila
add_executable(
    ${PROJECT_NAME}
    MACOSX_BUNDLE
    ${GAME_ALL_SOURCES}
    ${SFML_LIBRARIES}
    ${SNDFILE_LIBRARY}
    ${V8_LIBRARIES}
)

# link de bibliotecas
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SNDFILE_LIBRARY} ${V8_LIBRARIES})

# copia arquivos
if(APPLE)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${SFML_LIBRARY_DIR}" "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Frameworks"
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${SNDFILE_LIBRARY_DIR}" "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Frameworks"
    )
elseif(WIN32)
    # implementar
else()
    # implementar
endif()
