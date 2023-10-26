cmake_minimum_required(VERSION 3.22)
project(CSG)

find_package(glm REQUIRED)
add_subdirectory(strippedRayTracer)
set(CMAKE_CXX_STANDARD 23)

add_executable(CSG main.cpp
        csg_tree/node.cpp
        csg_tree/node.h
        csg_tree/node_type.cpp
        csg_tree/node_type.h
        csg_tree/edge.cpp
        csg_tree/edge.h
        objects/base_primitive.cpp
        objects/base_primitive.h
        objects/sphere.cpp
        objects/sphere.h
        objects/sphere.h
        objects/block.cpp
        objects/block.h
        objects/cylinder.cpp
        objects/cylinder.h
        csg_tree/utils.h
        csg_tree/utils.h
        csg_tree/utils.cpp
        csg_tree/utils.cpp
        csg_tree/root.cpp
        csg_tree/root.h
        csg_tree/primitive_node.cpp
        csg_tree/primitive_node.h
        csg_tree/boolean_operation_node.cpp
        csg_tree/boolean_operation_node.h
)

target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} RayTracer_redone)
set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)