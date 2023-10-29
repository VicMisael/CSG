//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_BASE_PRIMITIVE_H
#define CSG_BASE_PRIMITIVE_H


#include "../strippedRayTracer/RayTracerRedone/tracer/objects/VirtualObject.h"
#include "../strippedRayTracer/RayTracerRedone/tracer/scene/materials/Phong.h"
#include "../csg_tree/edge.h"
#include "rt_utils.h"


class base_primitive {
public:

    virtual csg_tree::classification classify(csg_tree::edge edge) = 0;

    virtual std::vector<rt_utils::csg_tree_intersection> intersects(const Ray &ray) const = 0;

    virtual void transform(Matrix4x4 m) {};

    rt_utils::primitive_type get_type();


protected:

    rt_utils::primitive_type type = rt_utils::NONE;

    explicit base_primitive(const rt_utils::primitive_type type = rt_utils::NONE) : material(
            std::make_shared<Phong>(ColorVec(0.5, 0.5, 0.5), 1, 1, 25)), type(type) {};

    std::shared_ptr<Phong> material;
};


#endif //CSG_BASE_PRIMITIVE_H
