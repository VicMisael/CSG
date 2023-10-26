//
// Created by Misael on 26/10/2023.
//

#ifndef CSG_ROOT_H
#define CSG_ROOT_H

#include <memory>
#include "node.h"

namespace csg_tree {

    class root : public base_primitive {
        std::shared_ptr<node> root_node;
    };

} // csg_tree

#endif //CSG_ROOT_H
