#include "csg_tree/edge.h"
#include "objects/sphere.h"
#include "csg_tree/root.h"
#include "csg_tree/primitive_node.h"
#include "strippedRayTracer/RayTracerRedone/RayTracerRedone.cpp"
#include "objects/block.h"
#include "csg_tree/boolean_operation_node.h"

int main() {
    const auto bloco = std::make_shared<block>(glm::vec3(0, 10, 15), 45);
    auto primitiveNode = std::make_shared<csg_tree::primitive_node>(bloco);
    auto raiz = std::make_shared<csg_tree::root>(primitiveNode);

    Raytracer::render1(raiz, "Teste1", 1000, 1000, 5);

    const auto esfera = std::make_shared<sphere>(glm::vec3(0, 30, 15), 65);
    auto primitiveNode1 = std::make_shared<csg_tree::primitive_node>(esfera);
    auto raiz2 = std::make_shared<csg_tree::root>(primitiveNode1);

    //Raytracer::render1(raiz2, "Teste2", 1000, 1000, 5);

    auto unionNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_union(primitiveNode, primitiveNode1));

    auto raiz3 = std::make_shared<csg_tree::root>(unionNode);
    //Raytracer::render2(raiz3, "union", 800, 800, 20);

    auto intersectionNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_intersection(primitiveNode, primitiveNode1));

    auto raiz4 = std::make_shared<csg_tree::root>(intersectionNode);
    //Raytracer::render2(raiz4, "intersection", 800, 800, 20);

    const auto esfera2 = std::make_shared<sphere>(glm::vec3(0, 30, -25), 30);
    auto primitiveNode2 = std::make_shared<csg_tree::primitive_node>(esfera2);
    auto testeSsfere = std::make_shared<csg_tree::root>(primitiveNode2);
   // Raytracer::render2(testeSsfere, "testeSsfere", 800, 800, 20);
    auto differenceNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_difference(primitiveNode, primitiveNode2));

    auto raiz5 = std::make_shared<csg_tree::root>(differenceNode);
    Raytracer::render4(raiz5, "difference", 800, 800, 20);


    return 0;
}
