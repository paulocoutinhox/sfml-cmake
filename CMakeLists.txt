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

#if(ARCH_32BITS) // usar depois

if(APPLE)
    set(TARGET_SYSTEM "mac")
    set(MACOSX_BUNDLE true)
elseif(WIN32)
    set(TARGET_SYSTEM "win32")
else()
    set(TARGET_SYSTEM "linux")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/cmake/modules")

set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")
set(JS_DIR "${CMAKE_SOURCE_DIR}/js")

set(SFML_ROOT "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")
set(SNDFILE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/sndfile/${TARGET_SYSTEM}/include")
set(SNDFILE_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/sndfile/${TARGET_SYSTEM}/lib")
set(V8_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/v8/${TARGET_SYSTEM}/include")
set(V8_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/v8/${TARGET_SYSTEM}/lib")

# nome do projeto
project(${PROJECT_NAME})

# icone do projeto
if(APPLE)
    set(MACOSX_BUNDLE_ICON_FILE "${RESOURCES_DIR}/icons/osx.icns")
elseif(WIN32)
    # implementar
else()
    # implementar
endif()

# biblioteca SFML
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

include_directories(
    ${SFML_INCLUDE_DIR}
)

# biblioteca SNDFILE
include_directories(
    ${SNDFILE_INCLUDE_DIR}
)

find_library(SNDFILE_LIBRARY sndfile ${SNDFILE_LIBRARY_DIR})

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

#set_target_properties(${PROJECT_NAME} PROPERTIES RESOURCE "${RESOURCES_DIR}")

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
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Resources/js"
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${JS_DIR}" "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Resources/js"
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${RESOURCES_DIR}" "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Resources"
    )
elseif(WIN32)
    # implementar
else()
    # implementar
endif()
