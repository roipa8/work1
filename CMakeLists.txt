# cmake_minimum_required(VERSION <specify CMake version here>)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment1 main.cpp json.hpp Session.h Session.cpp Graph.h Graph.cpp Agent.h Agent.cpp Tree.h Tree.cpp)