cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

project(lab11)

add_executable(
    run
    src/taskA.cpp
)
