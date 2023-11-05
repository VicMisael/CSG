//
// Created by Misael on 26/10/2023.
//

#include "boolean_operation_node.h"
#include "utils.h"
#include <algorithm>

namespace csg_tree {

    const auto compareDist = [](const rt_utils::csg_tree_intersection &a, const rt_utils::csg_tree_intersection &b) {
        return a.t < b.t;
    };


    std::vector<rt_utils::csg_tree_intersection> unionOperation(
            const std::vector<rt_utils::csg_tree_intersection> &leftIntersections,
            const std::vector<rt_utils::csg_tree_intersection> &rightIntersections) {
        std::vector<rt_utils::csg_tree_intersection> result;

        size_t i = 0, j = 0;
        while (i < leftIntersections.size() && j < rightIntersections.size()) {
            if (leftIntersections[i].t < rightIntersections[j].t) {
                result.push_back(leftIntersections[i]);
                i++;
            } else {
                result.push_back(rightIntersections[j]);
                j++;
            }
        }
        while (i < leftIntersections.size()) {
            result.push_back(leftIntersections[i]);
            i++;
        }
        while (j < rightIntersections.size()) {
            result.push_back(rightIntersections[j]);
            j++;
        }

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

    std::vector<rt_utils::csg_tree_intersection> differenceOperation(
            const std::vector<rt_utils::csg_tree_intersection> &leftIntersections,
            const std::vector<rt_utils::csg_tree_intersection> &rightIntersections) {

        std::vector<rt_utils::csg_tree_intersection> result;
        bool insideLeft = false;
        bool insideRight = false;
        size_t i = 0, j = 0;

        while (i < leftIntersections.size() && j < rightIntersections.size()) {
            if (leftIntersections[i].t < rightIntersections[j].t) {
                if (!insideRight) {
                    result.push_back(leftIntersections[i]);
                }
                insideLeft = leftIntersections[i].entry;
                i++;
            } else {
                if (insideLeft) {
                    rt_utils::csg_tree_intersection inter = rightIntersections[j];
                    inter.entry = !inter.entry;
                    inter.normal = -inter.normal;
                    result.push_back(inter);
                }
                insideRight = rightIntersections[j].entry;
                j++;
            }
        }

        while (i < leftIntersections.size()) {
            if (!insideRight) {
                result.push_back(leftIntersections[i]);
            }
            i++;
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


    std::vector<rt_utils::csg_tree_intersection> csg_tree::boolean_operation_node::intersects(const Ray &ray) const {
        std::vector<rt_utils::csg_tree_intersection> leftIntersections = this->left->intersects(ray);
        std::vector<rt_utils::csg_tree_intersection> rightIntersections = this->right->intersects(ray);

        //std::sort(leftIntersections.begin(), leftIntersections.end(), compareDist);
        //std::sort(rightIntersections.begin(), rightIntersections.end(), compareDist);

        std::vector<rt_utils::csg_tree_intersection> result;
        switch (this->operation) {
            case UNION:
                return unionOperation(leftIntersections, rightIntersections);
            case INTERSECTION:
                return intersectionOperation(leftIntersections, rightIntersections);
            case DIFFERENCE:
                return differenceOperation(leftIntersections, rightIntersections);
        }
        return result;
    }

    const classification boolean_operation_node::classify(const edge _edge) const {
        auto left = this->left->classify(_edge);
        auto right = this->right->classify(_edge);
        return utils::combine_classification(left, right, this->operation);
    }

} // csg_tree