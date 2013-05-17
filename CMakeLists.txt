# set minimum version required for CMake
cmake_minimum_required(VERSION 2.8)

# project variables
set(PROJECT_NAME "sfml-project")

# project source files
set(
    SRC
    ../main.cpp
    ../Engine.h
    ../Engine.cpp
    ../Util.h
    ../Util.cpp
)

if(APPLE)
    list(APPEND SRC ../ResourcePath.hpp)
    list(APPEND SRC ../ResourcePath.mm)
endif()

# setup target
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

set(SFML_ROOT "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/sfml/${TARGET_SYSTEM}/lib")
set(SNDFILE_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/sndfile/${TARGET_SYSTEM}/lib")
set(FREETYPE_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/library/freetype/${TARGET_SYSTEM}/lib")

# setup project name
project(${PROJECT_NAME})

# setup project icon
if(APPLE)
    set(MACOSX_BUNDLE_ICON_FILE "${RESOURCES_DIR}/icons/osx.icns")
elseif(WIN32)
    # NOT IMPLEMENTED - CAN YOU DO IT AND HELP THE PROJECT?
else()
    # NOT IMPLEMENTED - CAN YOU DO IT AND HELP THE PROJECT?
endif()

# setup library SFML
find_package(SFML 2 REQUIRED audio graphics network system window)

include_directories(
    ${SFML_INCLUDE_DIR}
)

# setup library SNDFILE
find_library(SNDFILE_LIBRARY sndfile ${SNDFILE_LIBRARY_DIR})

# setup library FREETYPE
find_library(FREETYPE_LIBRARY freetype ${FREETYPE_LIBRARY_DIR})

# setup compile process
add_executable(
    ${PROJECT_NAME}
    MACOSX_BUNDLE
    ${SRC}
    ${SFML_LIBRARIES}
    ${SNDFILE_LIBRARY}
    ${FREETYPE_LIBRARY}
)

# setup target links
if(APPLE)
    set(EXTRA_TARGET_LINK_LIBRARIES "-framework Foundation")
else()
    set(EXTRA_TARGET_LINK_LIBRARIES "")
endif()

target_link_libraries(${PROJECT_NAME} ${EXTRA_TARGET_LINK_LIBRARIES} ${SFML_LIBRARIES} ${SNDFILE_LIBRARY} ${FREETYPE_LIBRARY})

# copy files
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
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${FREETYPE_LIBRARY_DIR}" "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Frameworks"
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Resources/js"
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${RESOURCES_DIR}" "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.app/Contents/Resources"
    )
elseif(WIN32)
    # NOT IMPLEMENTED - CAN YOU DO IT AND HELP THE PROJECT?
else()
    # NOT IMPLEMENTED - CAN YOU DO IT AND HELP THE PROJECT?
endif()

# setup target mode ("debug" or "release")
set(TARGET_MODE "debug")

if(TARGET_MODE STREQUAL "debug")
    set(CMAKE_BUILD_TYPE Debug)
elseif(TARGET_MODE STREQUAL "release")
    set(CMAKE_BUILD_TYPE Release)
endif()
