//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_SPHERE_H
#define CSG_SPHERE_H


#include <glm/vec3.hpp>
#include "base_primitive.h"

class sphere:public base_primitive {
public:
    sphere(const glm::vec3 &center, float radius);

    std::optional<intersectionRec> intersects(const Ray &ray) const override;

    float getArea() const override;

    csg_tree::edge classify(const csg_tree::edge edge) override;

private:
    glm::vec3 center;
    float radius;
};


#endif //CSG_SPHERE_H
