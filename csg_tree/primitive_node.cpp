//
// Created by Misael on 26/10/2023.
//

#include "primitive_node.h"

namespace csg_tree {
    const node_type primitive_node::getType() const {
        return PRIMITIVE;
    }


    const classification primitive_node::classify(const edge _edge) const {
        return primitive->classify(_edge);
    }

    std::vector<rt_utils::csg_tree_intersection> primitive_node::intersects(const Ray &ray) {
        return primitive->intersects(ray);
    }
} // csg_tree