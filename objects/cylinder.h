//
// Created by Misael on 30/10/2023.
//

#ifndef CSG_CYLINDER_H
#define CSG_CYLINDER_H


#include "base_primitive.h"

class cylinder : public base_primitive {
public:
    cylinder(const glm::vec3 &center, float r, float h) : r(r), h(h), center(center) {}

    csg_tree::classification classify(csg_tree::edge edge) const override;

    std::vector<rt_utils::csg_tree_intersection> intersects(const Ray &ray) const override;

public:
    float r;  // radius
    float h;  // height
    glm::vec3 center;


};


#endif //CSG_CYLINDER_H
