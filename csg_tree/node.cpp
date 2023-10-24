//
// Created by Misael on 19/10/2023.
#include "node.h"

const csg_tree::node_type csg_tree::primitive_node::getType() const {
    return node_type::PRIMITIVE;
}

csg_tree::primitive_node::primitive_node(const std::shared_ptr<base_primitive> &primitive) : primitive(primitive) {}

csg_tree::boolean_operation_node
csg_tree::boolean_operation_node::csg_union(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right) {
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
