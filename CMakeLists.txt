cmake_minimum_required(VERSION 2.8)
project(TMP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror -pedantic")
# set(CMAKE_CXX_STANDARD 14)  # does not work with Travis
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(.)

add_subdirectory(tests)
