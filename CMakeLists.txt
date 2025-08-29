cmake_minimum_required(VERSION 3.16)
project(curves LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(curves SHARED
    src/circle.cpp
    src/ellipse.cpp
    src/spiral.cpp
)
target_include_directories(curves PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_subdirectory(app)