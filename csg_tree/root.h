//
// Created by Misael on 26/10/2023.
//

#ifndef CSG_ROOT_H
#define CSG_ROOT_H

#include <memory>
#include "node.h"

namespace csg_tree {

    class root : public VirtualObject {
    public:
        explicit root(const std::shared_ptr<node> &rootNode);

        classification classify(csg_tree::edge edge);

        [[nodiscard]] std::optional<intersectionRec> intersects(const Ray &ray) const override;

        float getArea() const override;

    private:
        std::shared_ptr<node> root_node;

    };

} // csg_tree

#endif //CSG_ROOT_H
