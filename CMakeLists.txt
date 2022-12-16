cmake_minimum_required(VERSION 3.21)
project(csv)

set(CMAKE_CXX_STANDARD 14)

add_executable(csv main.cpp tuple.h parser.h)
