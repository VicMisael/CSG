//
// Created by Misael on 26/10/2023.
//

#include "boolean_operation_node.h"

namespace csg_tree {
    csg_tree::boolean_operation_node csg_tree::boolean_operation_node::csg_union(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right) {
        return {left, right, csg_tree::UNION};
    }

    csg_tree::boolean_operation_node csg_tree::boolean_operation_node::csg_intersection(const std::shared_ptr<node> &left,
                                                                                        const std::shared_ptr<node> &right) {
        return {left, right, csg_tree::INTERSECTION};
    }

    csg_tree::boolean_operation_node csg_tree::boolean_operation_node::csg_difference(const std::shared_ptr<node> &left,
                                                                                      const std::shared_ptr<node> &right) {
        return {left, right, csg_tree::DIFFERENCE};
    }

    bool csg_tree::boolean_operation_node::intersects(const Ray &ray) const {
        return false;
    }

    csg_tree::edge csg_tree::boolean_operation_node::classify(const csg_tree::edge _edge) const {
        return edge();
    }

    std::optional<intersectionRec> csg_tree::boolean_operation_node::intersects(const Ray &ray) {
        return std::optional<intersectionRec>();
    }
} // csg_tree