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

private:
    glm::vec3 center;
    float radius;
};


#endif //CSG_SPHERE_H
