cmake_minimum_required(VERSION 3.16)

project(IRCClient)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SerenityOS_SOURCE_DIR $ENV{SERENITY_SOURCE_DIR})
include(${SerenityOS_SOURCE_DIR}/Meta/CMake/code_generators.cmake)
add_custom_target(all_generated)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${SerenityOS_SOURCE_DIR})
include_directories(${SerenityOS_SOURCE_DIR}/Userland/Libraries)

add_compile_options(-Wno-literal-suffix) # AK::StringView defines operator"" sv, which GCC complains does not have an underscore.
add_compile_options(-fno-gnu-keywords)   # JS::Value has a method named typeof, which also happens to be a GNU keyword.

compile_gml(src/IRCMainWindow.gml IRCMainWindowGML.h irc_main_window_gml)

set(SOURCES
        src/main.cpp
        src/MainWidget.cpp
        src/MainWidget.h
        IRCMainWindowGML.h)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} gui main gfx core cpp config desktop)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
