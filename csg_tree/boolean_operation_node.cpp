//
// Created by Misael on 26/10/2023.
//

#include "boolean_operation_node.h"
#include "utils.h"

namespace csg_tree {

    const auto compareDist = [](const rt_utils::csg_tree_intersection &a, const rt_utils::csg_tree_intersection &b) {
        return a.t < b.t;
    };


    std::vector<rt_utils::csg_tree_intersection> unionOperation(
            const std::vector<rt_utils::csg_tree_intersection> &leftIntersections,
            const std::vector<rt_utils::csg_tree_intersection> &rightIntersections) {
        std::vector<rt_utils::csg_tree_intersection> result;

        std::merge(leftIntersections.begin(), leftIntersections.end(), rightIntersections.begin(),
                   rightIntersections.end(), result.begin(), compareDist);

        return result;
    }

    std::vector<rt_utils::csg_tree_intersection> intersectionOperation(
            const std::vector<rt_utils::csg_tree_intersection> &leftIntersections,
            const std::vector<rt_utils::csg_tree_intersection> &rightIntersections) {

        std::vector<rt_utils::csg_tree_intersection> result;
        bool insideLeft = false;
        bool insideRight = false;
        size_t i = 0, j = 0;

        while (i < leftIntersections.size() && j < rightIntersections.size()) {
            if (leftIntersections[i].t < rightIntersections[j].t) {
                insideLeft = leftIntersections[i].entry;
                if (insideLeft && insideRight) {
                    result.push_back(leftIntersections[i]);
                }
                i++;
            } else {
                insideRight = rightIntersections[j].entry;
                if (insideRight && insideLeft) {
                    result.push_back(rightIntersections[j]);
                }
                j++;
            }
        }

        return result;
    }


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


    std::vector<rt_utils::csg_tree_intersection> csg_tree::boolean_operation_node::intersects(const Ray &ray) {
        std::vector<rt_utils::csg_tree_intersection> leftIntersections = this->left->intersects(ray);
        std::vector<rt_utils::csg_tree_intersection> rightIntersections = this->right->intersects(ray);

        std::sort(leftIntersections.begin(), leftIntersections.end(), compareDist);
        std::sort(rightIntersections.begin(), rightIntersections.end(), compareDist);

        std::vector<rt_utils::csg_tree_intersection> result;
        switch (this->operation) {
            case UNION:
                return unionOperation(leftIntersections, rightIntersections);
            case INTERSECTION:
                return intersectionOperation(leftIntersections, rightIntersections);
                break;
            case DIFFERENCE:
                return intersectionOperation(leftIntersections, rightIntersections);
                break;
        }
        return result;
    }

    const classification boolean_operation_node::classify(const edge _edge) const {
        auto left = this->left->classify(_edge);
        auto right = this->right->classify(_edge);
        return utils::combine_classification(left, right, this->operation);
    }

} // csg_tree