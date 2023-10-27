//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_EDGE_H
#define CSG_EDGE_H

#include <glm/vec3.hpp>
#include <vector>
#include "../strippedRayTracer/RayTracerRedone/tracer/scene/Ray.h"

namespace csg_tree {


    struct edge {
        glm::vec3 min;
        glm::vec3 max;
    };

    struct classification {
        std::vector<edge> EinS;
        std::vector<edge> EoutS;
        std::vector<edge> EonS;
    };
} // csg_tree

#endif //CSG_EDGE_H
