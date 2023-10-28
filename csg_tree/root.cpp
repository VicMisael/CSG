//
// Created by Misael on 26/10/2023.
//

#include "root.h"

namespace csg_tree {
    classification root::classify(csg_tree::edge edge) {
        return this->root_node->classify(edge);
    }

    std::optional<intersectionRec> root::intersects(const Ray &ray) const {
        auto intersects = this->root_node->intersects(ray);
        auto isEntry = [](rt_utils::csg_tree_intersection &a) {
            return a.entry;
        };

        if (intersects.empty()) {
            return {};
        }
        const auto result = intersects[0];
        return intersectionRec{result.t, result.hit, result.normal, result.material};
//        if (auto it = std::find_if(begin(intersects), end(intersects), isEntry); it != std::end(intersects)) {
//            const auto result = std::find_if(intersects.begin(), intersects.end(), isEntry);
//            return intersectionRec{result->t, result->hit, result->normal, result->material};
//        }
//        return {};

    }

    root::root(const std::shared_ptr<node> &rootNode) : root_node(rootNode) {}

    float root::getArea() const {
        return 0;
    }
} // csg_tree