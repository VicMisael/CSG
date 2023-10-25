//
// Created by misae on 25/10/2023.
//
#include "utils.h"

csg_tree::edge csg_tree::utils::from_ray(const Ray &ray) {
    glm::vec3 min = ray.origin;
    glm::vec3 max = ray.point_at(std::numeric_limits<float>::max());
    return csg_tree::edge{min, max};
}

