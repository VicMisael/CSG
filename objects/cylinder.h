//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_CYLINDER_H
#define CSG_CYLINDER_H


#include <glm/vec3.hpp>

class cylinder {
    glm::vec3 axis_; // cylinder axis_
    glm::vec3 base_;
    float height_;
    float radius_;
};


#endif //CSG_CYLINDER_H
