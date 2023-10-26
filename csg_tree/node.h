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

        [[nodiscard]] virtual bool intersects(const Ray &ray) const = 0;

        [[nodiscard]] virtual edge classify(edge _edge) const = 0;

        virtual std::optional<intersectionRec> intersects(const Ray &ray) = 0;
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
