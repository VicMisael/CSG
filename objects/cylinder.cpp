//
// Created by Misael on 21/10/2023.
//

#include "cylinder.h"

cylinder::cylinder(const glm::vec3 &axis, const glm::vec3 &base, float height, float radius) : axis_(axis), base_(base),
                                                                                               height_(height),
                                                                                               radius_(radius) {}


std::optional<intersectionRec> cylinder::intersects(const Ray &ray) const {
    return std::optional<intersectionRec>();
}

float cylinder::getArea() const {
    return 0;
}

csg_tree::edge cylinder::classify(const csg_tree::edge edge) {
    return csg_tree::edge();
}
