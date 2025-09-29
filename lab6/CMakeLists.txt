cmake_minimum_required(VERSION 3.10.0)
project(app VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

include_directories(include)

add_executable(app
    source/main.cpp
    source/bicycle.cpp
    source/menu.cpp
    source/utils.cpp
    source/car.cpp
    source/carriage.cpp
    source/transport.cpp
    source/exceptions.cpp
)