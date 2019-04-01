cmake_minimum_required(VERSION 3.10)
project(Median)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 14)

add_executable(Median test.cpp Median.cpp Median.h)
