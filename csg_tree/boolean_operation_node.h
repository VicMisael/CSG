//
// Created by Misael on 26/10/2023.
//

#ifndef CSG_BOOLEAN_OPERATION_NODE_H
#define CSG_BOOLEAN_OPERATION_NODE_H

#include "node.h"

namespace csg_tree {

    class boolean_operation_node : public with_children {
    public:
        static boolean_operation_node csg_union(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right);

        static boolean_operation_node
        csg_intersection(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right);

        static boolean_operation_node
        csg_difference(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right);

        std::vector<rt_utils::csg_tree_intersection> intersects(const Ray &ray) override;

        [[nodiscard]] const classification classify(const edge _edge) const override;

    private:
        boolean_operation_node(const std::shared_ptr<node> &left,
                               const std::shared_ptr<node> &right,
                               boolean_operation_type operation) :
                with_children(left, right), operation(operation) {}

        [[nodiscard]] const node_type getType() const override {
            return BOOLEAN;
        }

    private:
        boolean_operation_type operation;

    };

} // csg_tree

#endif //CSG_BOOLEAN_OPERATION_NODE_H
