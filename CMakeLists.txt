cmake_minimum_required(VERSION 3.16)

project(cmake-template)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Charts Gui)
qt_standard_project_setup()

## Compilation flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

## Folders
set(CMAKE_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(src)

add_executable(main
               src/chartview.cpp
               src/main.cpp)

target_link_libraries(main PUBLIC Qt::Core Qt::Charts Qt::Gui)
