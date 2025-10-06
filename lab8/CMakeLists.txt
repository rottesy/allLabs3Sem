cmake_minimum_required(VERSION 3.20.0)
project(app VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++20)



if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-std=c++20)
endif()

include_directories(include)

add_executable(app
    source/main.cpp
    source/menus.cpp
)