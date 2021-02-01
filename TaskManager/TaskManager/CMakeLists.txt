cmake_minimum_required(VERSION 3.17)
project(TaskManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskManager main.cpp Task.cpp Task.h)