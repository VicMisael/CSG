//
// Created by Misael on 19/10/2023.
#include "node.h"

const csg_tree::node_type csg_tree::primitive_node::getType() const {
    return node_type::PRIMITIVE;
}
