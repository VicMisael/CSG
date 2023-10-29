//
// Created by Misael on 26/10/2023.
//

#ifndef CSG_PRIMITIVE_NODE_H
#define CSG_PRIMITIVE_NODE_H

#include "node.h"

namespace csg_tree {

    class primitive_node : public node {
    public:
        explicit primitive_node(const std::shared_ptr<base_primitive> &primitive) : primitive(primitive) {

        }

        [[nodiscard]] const node_type getType() const override;

        [[nodiscard]] const classification classify(edge _edge) const override;

        std::vector<rt_utils::csg_tree_intersection>intersects(const Ray &ray) const override;

    private:
        std::shared_ptr<base_primitive> primitive;
    };


} // csg_tree

#endif //CSG_PRIMITIVE_NODE_H
