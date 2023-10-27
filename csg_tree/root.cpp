//
// Created by Misael on 26/10/2023.
//

#include "root.h"

namespace csg_tree {
    classification root::classify(csg_tree::edge edge) {
        return this->root_node->classify(edge);
    }

    std::optional<intersectionRec> root::intersects(const Ray &ray) const {
        this->root_node->intersects(ray);
    }
} // csg_tree