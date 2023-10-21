//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_EDGE_H
#define CSG_EDGE_H

#include <glm/vec3.hpp>

namespace csg_tree {

    class edge {
        glm::vec3 min;
        glm::vec3 max;
    };

} // csg_tree

#endif //CSG_EDGE_H
