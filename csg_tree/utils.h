//
// Created by misae on 25/10/2023.
//

#ifndef CSG_UTILS_H
#define CSG_UTILS_H

#include "../strippedRayTracer/RayTracerRedone/tracer/scene/Ray.h"
#include "edge.h"

namespace csg_tree::utils {

    edge from_ray(const Ray& ray);
}

#endif //CSG_UTILS_H
