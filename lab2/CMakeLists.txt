cmake_minimum_required(VERSION 3.10.0)
project(array_app VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

add_executable(array_app
    source/main.cpp
    source/array.cpp
    source/menu.cpp
    source/utils.cpp
)

