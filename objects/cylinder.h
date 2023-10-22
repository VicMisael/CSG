//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_CYLINDER_H
#define CSG_CYLINDER_H


#include <glm/vec3.hpp>
#include "base_primitive.h"

class cylinder: public base_primitive{
    glm::vec3 axis_; // cylinder axis_
    glm::vec3 base_;
    float height_;
    float radius_;
};


#endif //CSG_CYLINDER_H
