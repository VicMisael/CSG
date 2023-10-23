//
// Created by Misael on 19/10/2023.
//

#ifndef CSG_NODE_H
#define CSG_NODE_H

#include <memory>
#include "node_type.h"

namespace csg_tree {
    class node {
    public:
        [[nodiscard]] virtual const node_type getType() const = 0;
    };

    class primitive_node : public node {
    public:
        explicit primitive_node(const std::shared_ptr<base_primitive> &primitive);

        [[nodiscard]] const node_type getType() const override;

    private:
        std::shared_ptr<base_primitive> primitive;
    };

    class with_children : public node {
    public:
        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
    protected:
        with_children(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right)
                : left(left), right(right) {}

    };

    class boolean_operation_node : public with_children {
    public:
        static boolean_operation_node csg_union(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right);

        static boolean_operation_node csg_intersection(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right);

    private:
        boolean_operation_node(const std::shared_ptr<node> &left,
                               const std::shared_ptr<node> &right, boolean_operation_type operation) :
                with_children(left, right), operation(operation) {}

        [[nodiscard]] const node_type getType() const override {
            return BOOLEAN;
        }

    private:
        boolean_operation_type operation;

    };
}


#endif //CSG_NODE_H
