//
// Created by Misael on 19/10/2023.
//

#ifndef CSG_NODE_TYPE_H
#define CSG_NODE_TYPE_H

#include "../objects/base_primitive.h"

namespace csg_tree {
    enum node_type {
        GEOMETRIC,
        BOOLEAN,
        PRIMITIVE
    };

    enum boolean_operation_type {
        UNION,
        INTERSECTION,
        DIFFERENCE,
    };

}


#endif //CSG_NODE_TYPE_H
