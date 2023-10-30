#include "csg_tree/edge.h"
#include "objects/sphere.h"
#include "csg_tree/root.h"
#include "csg_tree/primitive_node.h"
#include "objects/block.h"
#include "csg_tree/boolean_operation_node.h"
#include "strippedRayTracer/RayTracerRedone/RayTracerRedone.cpp"


std::shared_ptr<csg_tree::node> generateObject2() {
    const auto bloco = std::make_shared<block>(glm::vec3(0, 45, 15), 45);
    auto primitiveNode = std::make_shared<csg_tree::primitive_node>(bloco);

    const auto esfera2 = std::make_shared<sphere>(glm::vec3(0, 30, -25), 30);
    auto primitiveNode2 = std::make_shared<csg_tree::primitive_node>(esfera2);
    // Raytracer::render2(testeSsfere, "testeSsfere", 800, 800, 20);
    return std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_difference(primitiveNode, primitiveNode2));
}

std::shared_ptr<csg_tree::node> generateObject() {
    const auto bloco = std::make_shared<block>(glm::vec3(0, 45, 15), 45);
    auto primitiveNode = std::make_shared<csg_tree::primitive_node>(bloco);
    const auto esfera2 = std::make_shared<sphere>(glm::vec3(0, 30, -25), 30);
    auto primitiveNode2 = std::make_shared<csg_tree::primitive_node>(esfera2);
    const auto esfera = std::make_shared<sphere>(glm::vec3(0, 30, 15), 65);
    auto primitiveNode1 = std::make_shared<csg_tree::primitive_node>(esfera);
    auto differenceNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_difference(primitiveNode, primitiveNode2));
    auto diffIntersection = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_intersection(differenceNode, primitiveNode1));

    return diffIntersection;
}

std::shared_ptr<csg_tree::node> generateObject3() {
    const auto bloco = std::make_shared<block>(glm::vec3(0, 45, 15), 45);

    auto primitiveNode = std::make_shared<csg_tree::primitive_node>(bloco);

    const auto esfera2 = std::make_shared<sphere>(glm::vec3(0, 30, -25), 30);
    auto primitiveNode2 = std::make_shared<csg_tree::primitive_node>(esfera2);
    const auto esfera = std::make_shared<sphere>(glm::vec3(0, 30, 15), 65);
    auto primitiveNode1 = std::make_shared<csg_tree::primitive_node>(esfera);

    auto differenceNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_difference(primitiveNode, primitiveNode2));

    auto diffIntersection = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_intersection(differenceNode, primitiveNode1));


    const auto bloco4 = std::make_shared<block>(glm::vec3(45, 45, 65), 45);

    auto bloco4Node = std::make_shared<csg_tree::primitive_node>(bloco4);

    auto unionDiffIntersection = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_union(diffIntersection, bloco4Node)
    );
    return unionDiffIntersection;
}


int main() {

    const auto bloco = std::make_shared<block>(glm::vec3(0, 45, 15), 45);
    auto primitiveNode = std::make_shared<csg_tree::primitive_node>(bloco);

    auto raiz = std::make_shared<csg_tree::root>(primitiveNode);

//    Raytracer::render1(raiz, "Teste1", 1000, 1000, 5);

    const auto esfera = std::make_shared<sphere>(glm::vec3(0, 30, 15), 65);
    auto primitiveNode1 = std::make_shared<csg_tree::primitive_node>(esfera);
    auto raiz2 = std::make_shared<csg_tree::root>(primitiveNode1);

//    Raytracer::render1(raiz2, "Teste2", 1000, 1000, 5);

    auto unionNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_union(primitiveNode, primitiveNode1));

    auto raiz3 = std::make_shared<csg_tree::root>(unionNode);
//    Raytracer::render2(raiz3, "union", 800, 800, 20);

    auto intersectionNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_intersection(primitiveNode, primitiveNode1));

    auto raiz4 = std::make_shared<csg_tree::root>(intersectionNode);
//    Raytracer::render2(raiz4, "intersection", 800, 800, 20);


    auto raiz5 = std::make_shared<csg_tree::root>(generateObject2());
//    Raytracer::render3(raiz5, "difference", 1000, 1000, 5);
//    Raytracer::render4(raiz5, "difference2", 1000, 1000, 5);
//    Raytracer::render5(raiz5, "difference3", 1000, 1000, 5);


    auto raiz6 = std::make_shared<csg_tree::root>(generateObject(), true);
    auto raiz7 = std::make_shared<csg_tree::root>(generateObject3(), false);

//    Raytracer::render3(raiz6, "teste", 2000, 2000, 1);
    Raytracer::render3(raiz6, "teste", 1350, 1350, 20);


    return 0;
}
