cmake_minimum_required(VERSION 3.22)
project(CSG)

set(CMAKE_CXX_STANDARD 23)

add_executable(CSG main.cpp
        csg_tree/csg_tree.h
)
