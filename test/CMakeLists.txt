cmake_minimum_required(VERSION 3.14)
project(test)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-O2 -g -Wall -Wextra -W)
include_directories(../type ../container)

add_executable(type type.cpp ../type/pair.h ../type/map.h)