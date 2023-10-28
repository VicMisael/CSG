//
// Created by misae on 25/10/2023.
//
#include "utils.h"

csg_tree::edge csg_tree::utils::from_ray(const Ray &ray) {
    glm::vec3 min = ray.origin;
    glm::vec3 max = ray.point_at((float) 10000000);
    return csg_tree::edge{min, max};
}

csg_tree::classification
csg_tree::utils::combine_classification(const csg_tree::classification &left, const csg_tree::classification &right,
                                        csg_tree::boolean_operation_type operation) {
    std::vector<edge> combinedInEdges;
    switch (operation) {
        case UNION: {
            combinedInEdges = left.getInEdges();
            for (const auto &eRight: right.getInEdges()) {
                bool added = false;
                for (auto &eLeft: combinedInEdges) {
                    if (eLeft.overlaps(eRight)) {
                        eLeft.min = eLeft.isLessThan(eLeft.min, eRight.min) ? eLeft.min : eRight.min;
                        eLeft.max = eLeft.isLessThan(eRight.max, eLeft.max) ? eRight.max : eLeft.max;
                        added = true;
                        break;
                    }
                }
                if (!added) {
                    combinedInEdges.push_back(eRight);
                }
            }
        }
            break;
        case INTERSECTION: {
            for (const auto &eLeft: left.getInEdges()) {
                for (const auto &eRight: right.getInEdges()) {
                    if (eLeft.overlaps(eRight)) {
                        combinedInEdges.push_back({glm::max(eLeft.min, eRight.min), glm::min(eLeft.max, eRight.max)});
                    }
                }
            }
        }
            break;
        case DIFFERENCE: {
            combinedInEdges = left.getInEdges();
            for (const auto &eRight: right.getInEdges()) {
                combinedInEdges.erase(
                        std::remove_if(combinedInEdges.begin(), combinedInEdges.end(),
                                       [&](const edge &e) { return e.overlaps(eRight); }),
                        combinedInEdges.end());
            }
        }
            break;
    }
    return {combinedInEdges, left.getEdge()};
}



