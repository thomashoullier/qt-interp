cmake_minimum_required(VERSION 3.16)

project(qt-interp)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Charts Gui)
qt_standard_project_setup()

## Compilation flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

## Folders
set(CMAKE_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(qt-interp
	       src/lagrange_interp.cpp
               src/chartview.cpp src/points.cpp src/poly_points.cpp
               src/main.cpp)

target_link_libraries(qt-interp PRIVATE Qt6::Charts)
