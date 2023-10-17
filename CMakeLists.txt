cmake_minimum_required(VERSION 3.22)
project(CSG)

find_package(glm REQUIRED)
add_subdirectory(strippedRayTracer)
set(CMAKE_CXX_STANDARD 23)

add_executable(CSG main.cpp
        csg_tree/csg_tree.h
)

target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} RayTracer_redone)
set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)