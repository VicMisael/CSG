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
        std::vector<csg_tree::edge> classify(csg_tree::edge edge);

        [[nodiscard]] std::optional<intersectionRec> intersects(const Ray &ray) const override;

    private:
        std::shared_ptr<node> root_node;

    };

} // csg_tree

#endif //CSG_ROOT_H
