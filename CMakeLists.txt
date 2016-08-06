cmake_minimum_required (VERSION 2.6)
project (learntris)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++17")
add_executable(learntris learntris.cpp Grid.cpp)
