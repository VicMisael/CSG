//
// Created by Misael on 27/10/2023.
//

#ifndef CSG_RT_UTILS_H
#define CSG_RT_UTILS_H


#include <glm/vec3.hpp>
#include <memory>
#include "../strippedRayTracer/RayTracerRedone/tracer/scene/materials/Material.h"

namespace rt_utils {
    struct csg_tree_intersection {
        float t;
        glm::vec3 hit;
        glm::vec3 normal;
        std::shared_ptr<Material> material;
        bool entry = false;
    };
};


#endif //CSG_RT_UTILS_H
