//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_EDGE_H
#define CSG_EDGE_H

#include <glm/vec3.hpp>
#include <vector>
#include "../strippedRayTracer/RayTracerRedone/tracer/scene/Ray.h"

namespace csg_tree {


    struct edge {
        glm::vec3 min;
        glm::vec3 max;
        [[nodiscard]] bool isLessThan(const glm::vec3 &a, const glm::vec3 &b) const {
            // Assuming z-order for comparison
            return a.z < b.z || (a.z == b.z && (a.y < b.y || (a.y == b.y && a.x < b.x)));
        }

        [[nodiscard]] bool overlaps(const edge& other) const {
            return !(isLessThan(max, other.min) || isLessThan(other.max, min));
        }
    };

    class classification {
    public:
        classification(const std::vector<edge> &einS, edge E);
        [[nodiscard]] std::vector<edge> getInEdges() const { return EinS; }

        const edge &getEdge() const;

    private:
        std::vector<edge> EinS;
        edge Edge;

        void sort();
    };
} // csg_tree

#endif //CSG_EDGE_H
