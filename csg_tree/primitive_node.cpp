//
// Created by Misael on 26/10/2023.
//

#include "primitive_node.h"

namespace csg_tree {
    const node_type primitive_node::getType() const {
        return PRIMITIVE;
    }

    bool primitive_node::intersects(const Ray &ray) const {
        return primitive->intersects(ray).has_value();
    }

    const classification primitive_node::classify(const edge _edge) const {
        return primitive->classify(_edge);
    }

    std::optional<intersectionRec> primitive_node::intersects(const Ray &ray) {
        return primitive->intersects(ray);
    }
} // csg_tree