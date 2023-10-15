//
// Created by Misael on 15/10/2023.
//

#ifndef CSG_CSG_TREE_H
#define CSG_CSG_TREE_H
namespace csg_tree {
    class node {
        csg_tree::node left;
        csg_tree::node right;

    };

    class node_type {

    };


    class geometric_operation : node_type {

    };

    class primitive : node_type {

    };

    enum boolean_operation_type {
        UNION,
        INTERSECTION,
        DIFFERENCE,
    };

    class boolean_operation : node_type {
        boolean_operation_type type;
    };

}
#endif //CSG_CSG_TREE_H
