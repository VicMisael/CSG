#include "csg_tree/edge.h"
#include "objects/sphere.h"
#include "csg_tree/root.h"
#include "csg_tree/primitive_node.h"
#include "objects/block.h"
#include "csg_tree/boolean_operation_node.h"
#include "strippedRayTracer/RayTracerRedone/RayTracerRedone.cpp"
#include "cylinder.h"

const auto matte = std::make_shared<Matte>(1, ColorVec(1, .05, 0));
const auto phongMetal = std::make_shared<PhongMetal>();
const auto reflexive = std::make_shared<PhongReflective>(ColorVec(Constants::BLACK), 1, 25, 1);

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


std::shared_ptr<csg_tree::node> generateObject3WithMaterial() {
    const auto bloco = std::make_shared<block>(glm::vec3(0, 45, 15), 45);
    bloco->set_material(matte);
    auto primitiveNode = std::make_shared<csg_tree::primitive_node>(bloco);

    const auto esfera2 = std::make_shared<sphere>(glm::vec3(0, 30, -25), 30);
    esfera2->set_material(reflexive);
    auto primitiveNode2 = std::make_shared<csg_tree::primitive_node>(esfera2);
    const auto esfera = std::make_shared<sphere>(glm::vec3(0, 30, 15), 65);
    auto primitiveNode1 = std::make_shared<csg_tree::primitive_node>(esfera);


    auto differenceNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_difference(primitiveNode, primitiveNode2));

    auto diffIntersection = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_intersection(differenceNode, primitiveNode1));

    return diffIntersection;
}

std::shared_ptr<csg_tree::node> generateObject4() {
    const auto cyl = std::make_shared<cylinder>(glm::vec3(0, 45, 15), 20, 105);
    const auto cylNode = std::make_shared<csg_tree::primitive_node>(cyl);

    const auto unionDiffIntersection = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_union(generateObject(), cylNode)
    );
    return unionDiffIntersection;
}

std::shared_ptr<csg_tree::node> footballBall() {
    const auto esfera2 = std::make_shared<sphere>(glm::vec3(10, 30, 15), 65);
    auto primitiveNode2 = std::make_shared<csg_tree::primitive_node>(esfera2);
    const auto esfera = std::make_shared<sphere>(glm::vec3(32.5, 30, 15), 65);;
    auto primitiveNode1 = std::make_shared<csg_tree::primitive_node>(esfera);

    auto diffIntersection = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_difference(primitiveNode2, primitiveNode1));

    return diffIntersection;
}

int main() {

    const auto bloco = std::make_shared<block>(glm::vec3(0, 45, 15), 45);
    auto primitiveNode = std::make_shared<csg_tree::primitive_node>(bloco);

    auto raiz = std::make_shared<csg_tree::root>(primitiveNode);

    Raytracer::render1(raiz, "Teste1", 500, 500, 115);

    const auto esfera = std::make_shared<sphere>(glm::vec3(0, 30, 15), 165);
    auto primitiveNode1 = std::make_shared<csg_tree::primitive_node>(esfera);
    auto raiz2 = std::make_shared<csg_tree::root>(primitiveNode1);

    Raytracer::render1(raiz2, "Teste2", 500, 500, 155);

    auto unionNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_union(primitiveNode, primitiveNode1));

    auto raiz3 = std::make_shared<csg_tree::root>(unionNode);
    Raytracer::render2(raiz3, "union", 500, 500, 150);

    auto intersectionNode = std::make_shared<csg_tree::boolean_operation_node>(
            csg_tree::boolean_operation_node::csg_intersection(primitiveNode, primitiveNode1));

    auto raiz4 = std::make_shared<csg_tree::root>(intersectionNode);
    Raytracer::render2(raiz4, "intersection", 800, 800, 160);


    auto raiz5 = std::make_shared<csg_tree::root>(generateObject2());
    Raytracer::render3(raiz5, "difference", 500, 500, 155);
    Raytracer::render4(raiz5, "difference2", 500, 500, 156);
    Raytracer::render5(raiz5, "difference3", 500, 500, 156);


    auto raiz6 = std::make_shared<csg_tree::root>(generateObject4(), true);
    auto raiz7 = std::make_shared<csg_tree::root>(generateObject3(), false);

    Raytracer::render3(raiz6, "raiz6", 500, 500, 155);
    Raytracer::render1(raiz6, "raiz7", 550, 550, 155);

    Raytracer::render3(raiz7, "raiz7-2", 500, 500, 155);

    auto raiz8 = std::make_shared<csg_tree::root>(generateObject3(), true);

    Raytracer::render3(raiz7, "raiz8", 500, 500, 155);


    auto football = std::make_shared<csg_tree::root>(footballBall());

    Raytracer::render3(football, "football", 500, 500, 150);

    auto bagunca = std::make_shared<csg_tree::root>(generateObject3WithMaterial());
    Raytracer::render1(bagunca, "bagunca", 500, 500, 50);


    return 0;
}
