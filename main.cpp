#include <iostream>
#include "csg_tree/edge.h"
#include "csg_tree/utils.h"
#include "objects/sphere.h"

int main() {
    sphere esferateste(glm::vec3(0, 10, 15), 150);
    auto dir = glm::vec3(0, 10, 15) - glm::vec3(15, 15, -200);
    float len = glm::length(dir);
    Ray ray(glm::vec3(15, 15, -200), glm::normalize(dir));
    auto result = esferateste.intersects(ray);
    auto edge = csg_tree::utils::from_ray(ray);
    auto classification = esferateste.classify(edge);
    return 0;
}
