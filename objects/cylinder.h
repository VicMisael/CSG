//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_CYLINDER_H
#define CSG_CYLINDER_H


#include <glm/vec3.hpp>
#include "base_primitive.h"

class cylinder: public base_primitive{
public:
    cylinder(const glm::vec3 &axis, const glm::vec3 &base, float height, float radius);


    std::optional<intersectionRec> intersects(const Ray &ray) const override;

    float getArea() const override;

    csg_tree::edge classify(const csg_tree::edge edge) override;

private:
    glm::vec3 axis_; // cylinder axis_
    glm::vec3 base_;
    float height_;
    float radius_;
};


#endif //CSG_CYLINDER_H
