cmake_minimum_required(VERSION 3.3)
project(TMP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Werror -pedantic")

include_directories(.)

add_subdirectory(tests)
