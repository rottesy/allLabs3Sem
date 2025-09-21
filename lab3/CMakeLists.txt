cmake_minimum_required(VERSION 3.10.0)
project(app VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

add_executable(app
    source/mai.cpp
    source/Bicycle.cpp
    source/menu.cpp
    source/utils.cpp
    source/Car.cpp
    source/Carriage.cpp
    source/Transport.cpp
)

