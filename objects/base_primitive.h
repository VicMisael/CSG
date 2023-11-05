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

    virtual csg_tree::classification classify(csg_tree::edge edge) const = 0;

    virtual std::vector<rt_utils::csg_tree_intersection> intersects(const Ray &ray) const = 0;

    void set_material(std::shared_ptr<Material> newMaterial);

    virtual void transform(Matrix4x4 m) {};

    rt_utils::primitive_type get_type();


protected:

    rt_utils::primitive_type type = rt_utils::NONE;

    explicit base_primitive(const rt_utils::primitive_type type = rt_utils::NONE) : type(type), material(
            std::make_shared<Phong>(ColorVec(0.5, 0.5, 0.5), 1, 1, 25)) {};

    std::shared_ptr<Material> material;
};


#endif //CSG_BASE_PRIMITIVE_H
