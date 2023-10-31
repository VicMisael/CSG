//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_BLOCK_H
#define CSG_BLOCK_H


#include "base_primitive.h"

class block : public base_primitive {
private:
    glm::vec3 min;
    glm::vec3 max;
public:

    block(const glm::vec3 &min, const glm::vec3 &max) : base_primitive(rt_utils::BLOCK), min(min), max(max) {}

    block(const glm::vec3 center, float length) : min(center - glm::vec3(length)),
                                                  max(center + glm::vec3(length)),
                                                  base_primitive(rt_utils::BLOCK) {

    };

    [[nodiscard]] std::vector<rt_utils::csg_tree_intersection> intersects(const Ray &ray) const override;

    csg_tree::classification classify(csg_tree::edge edge)  const override;

    void transform(Matrix4x4 m) override;


};


#endif //CSG_BLOCK_H
