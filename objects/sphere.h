//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_SPHERE_H
#define CSG_SPHERE_H


#include <glm/vec3.hpp>
#include "base_primitive.h"

class sphere : public base_primitive {
public:
    sphere(const glm::vec3 &center, float radius);

    [[nodiscard]] std::vector<rt_utils::csg_tree_intersection> intersects(const Ray &ray) const override;

    csg_tree::classification classify(const csg_tree::edge edge) override;

    void transform(Matrix4x4 m) override;

private:
    glm::vec3 center;
    float radius;
};


#endif //CSG_SPHERE_H
