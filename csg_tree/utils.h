//
// Created by misae on 25/10/2023.
//

#ifndef CSG_UTILS_H
#define CSG_UTILS_H

#include "../strippedRayTracer/RayTracerRedone/tracer/scene/Ray.h"
#include "edge.h"
#include "node_type.h"

namespace csg_tree::utils {

    edge from_ray(const Ray &ray);

    classification combine_classification(classification left, classification right, boolean_operation_type operation);
}

#endif //CSG_UTILS_H
