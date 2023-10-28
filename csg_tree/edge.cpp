//
// Created by Misael on 21/10/2023.
//

#include "edge.h"

bool isPointCBeforeD(const csg_tree::edge E, const glm::vec3 &C, const glm::vec3 &D) {
    auto A = E.min;
    auto B = E.max;
    glm::vec3 v = B - A;

    // Project C and D onto the line AB
    float projC = glm::dot(C - A, v) / glm::dot(v, v);
    float projD = glm::dot(D - A, v) / glm::dot(v, v);

    // Compare projections
    return projC < projD;
}


namespace csg_tree {
    classification::classification(const std::vector<edge> &einS, const edge E) :
            EinS(einS), Edge(E) {
        this->sort();
        // Sort based on the min member of the edge structure
    }

    void classification::sort() {
        // Sort based on the min member of the edge structure.
        const auto &E = this->Edge;
        std::sort(EinS.begin(), EinS.end(), [&](const edge &a, const edge &b) {
            return isPointCBeforeD(E, a.min, b.max);
        });

    }

    const edge &classification::getEdge() const {
        return Edge;
    }
} // csg_tree