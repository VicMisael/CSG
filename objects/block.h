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

    block(const glm::vec3 &min, const glm::vec3 &max) : min(min), max(max) {}

    block(const glm::vec3 center, float length) : min(center - glm::vec3(length)),
                                                  max(center + glm::vec3(length)) {

    };

    [[nodiscard]] std::optional<intersectionRec> intersects(const Ray &ray) const override;

    std::vector<csg_tree::edge> classify(csg_tree::edge edge) override;

    void transform(Matrix4x4 m) override;


};


#endif //CSG_BLOCK_H
