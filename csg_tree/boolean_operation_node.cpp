//
// Created by Misael on 26/10/2023.
//

#include "boolean_operation_node.h"

namespace csg_tree {
    csg_tree::boolean_operation_node
    csg_tree::boolean_operation_node::csg_union(const std::shared_ptr<node> &left, const std::shared_ptr<node> &right) {
        return {left, right, csg_tree::UNION};
    }

    csg_tree::boolean_operation_node
    csg_tree::boolean_operation_node::csg_intersection(const std::shared_ptr<node> &left,
                                                       const std::shared_ptr<node> &right) {
        return {left, right, csg_tree::INTERSECTION};
    }

    csg_tree::boolean_operation_node csg_tree::boolean_operation_node::csg_difference(const std::shared_ptr<node> &left,
                                                                                      const std::shared_ptr<node> &right) {
        return {left, right, csg_tree::DIFFERENCE};
    }

    bool csg_tree::boolean_operation_node::intersects(const Ray &ray) const {
        switch (this->operation) {
            case UNION:
                this->left->intersects(ray) || this->right->intersects(ray);
                break;
            case INTERSECTION:
                this->left->intersects(ray) && this->right->intersects(ray);
                break;
            case DIFFERENCE:
                this->left->intersects(ray) && !this->right->intersects(ray);
                break;
        }
    }


    std::optional<intersectionRec> csg_tree::boolean_operation_node::intersects(const Ray &ray) {
        std::optional<intersectionRec> left = this->left->intersects(ray);
        std::optional<intersectionRec> right = this->left->intersects(ray);
        switch (this->operation) {
            case UNION: {

            }
                break;
            case INTERSECTION:
                break;
            case DIFFERENCE:
                break;
        }
        return {};
    }

    const std::vector<edge> boolean_operation_node::classify(const edge _edge) const {
        return std::vector<edge>();
    }
} // csg_tree