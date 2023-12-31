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

        [[nodiscard]] virtual const classification classify(const edge _edge) const = 0;

        virtual std::vector<rt_utils::csg_tree_intersection> intersects(const Ray &ray) const = 0;
    };

    class with_children : public node {
    public:
        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
    protected:
        with_children(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right)
                : left(left), right(right) {}

    };


}


#endif //CSG_NODE_H
