cmake_minimum_required(VERSION 3.10.0)
project(matrix_app VERSION 0.1.0 LANGUAGES C CXX)


include_directories(include)

add_executable(matrix_app
    src/main.cpp
    src/Matrix.cpp
    src/menu.cpp
)