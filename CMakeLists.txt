cmake_minimum_required(VERSION 3.10)
project(MedianTest)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 14)

add_executable(MedianTest test.cpp Median.h)
