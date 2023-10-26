//
// Created by Misael on 21/10/2023.
//

#include "sphere.h"

sphere::sphere(const glm::vec3 &center, float radius) : center(center), radius(radius) {}

bool sphere::classify(csg_tree::edge edge) {
    return false;
}

std::optional<intersectionRec> sphere::intersects(const Ray &ray) const {
    return std::optional<intersectionRec>();
}

float sphere::getArea() const {
    return 0;
}

csg_tree::edge sphere::classify(const csg_tree::edge edge) {
    return csg_tree::edge();
}
