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
        objects/rt_utils.cpp
        objects/rt_utils.h
        objects/rt_utils.h
)

target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} RayTracer_redone)
set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
if (MSVC)
    target_link_options(${PROJECT_NAME} PUBLIC "/INCREMENTAL")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 ")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/O2")
endif (MSVC)
if (UNIX)
    set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -mavx2 -ffast-math")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Ofast -mavx2 -og -ffast-math")
endif (UNIX)