//
// Created by Misael on 26/10/2023.
//

#include "root.h"

const auto RED = std::make_shared<Phong>(ColorVec(1, 0.2, 0.2), 1, 1, 25);
const auto BLUE = std::make_shared<Phong>(ColorVec(0.2, 0.2, 1), 1, 1, 25);
const auto GREY = std::make_shared<Phong>(ColorVec(0.5, 0.5, 0.5), 1, 1, 25);
namespace csg_tree {
    classification root::classify(csg_tree::edge edge) {
        return this->root_node->classify(edge);
    }

    std::optional<intersectionRec> root::intersects(const Ray &ray) const {
        auto intersects = this->root_node->intersects(ray);
        if (intersects.empty()) {
            return {};
        }
        const auto result = intersects[0];
        if (color_object_types) {
            auto material = GREY;

            switch (result.type) {
                case rt_utils::BLOCK:
                    material = RED;
                    break;
                case rt_utils::SPHERE:
                    material = BLUE;
                    break;
            }

            return intersectionRec{result.t, result.hit, result.normal, material};
        }
        return intersectionRec{result.t, result.hit, result.normal, result.material};
    }

    root::root(const std::shared_ptr<node> &rootNode, bool color_object_types) : root_node(rootNode),
                                                                                 color_object_types(
                                                                                         color_object_types) {}

    float root::getArea() const {
        return 0;
    }
} // csg_tree