cmake_minimum_required(VERSION 3.16.0)

project(qt6ct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_BUILD_RPATH_USE_ORIGIN ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets OPTIONAL_COMPONENTS LinguistTools)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/qt6ct-common)

add_link_options(-Wl,--no-undefined)
add_subdirectory(src/main)
add_subdirectory(src/qt6ct-common)
