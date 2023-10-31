//
// Created by Misael on 30/10/2023.
//

#include "cylinder.h"

csg_tree::classification cylinder::classify(csg_tree::edge edge) const{

    glm::vec3 d = edge.max - edge.min; // direction vector
    glm::vec3 o = edge.min - center;   // translated origin

    float a = d.x * d.x + d.z * d.z;
    float b = 2.0 * (o.x * d.x + o.z * d.z);
    float c = o.x * o.x + o.z * o.z - r*r;

    float discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return csg_tree::classification({}, edge); // No intersection
    }

    float sqrtDiscriminant = sqrt(discriminant);
    float t1 = (-b - sqrtDiscriminant) / (2*a);
    float t2 = (-b + sqrtDiscriminant) / (2*a);

    glm::vec3 intPoint1 = edge.min + t1 * d;
    glm::vec3 intPoint2 = edge.min + t2 * d;

    bool intPoint1Inside = (intPoint1.y >= center.y - h/2.0 && intPoint1.y <= center.y + h/2.0);
    bool intPoint2Inside = (intPoint2.y >= center.y - h/2.0 && intPoint2.y <= center.y + h/2.0);

    if (intPoint1Inside && intPoint2Inside) {
        // Both intersections are valid
        if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
            return csg_tree::classification({csg_tree::edge(intPoint1, intPoint2)}, edge);
        }
    } else if (intPoint1Inside) {
        // Only intPoint1 is valid
        if (t1 >= 0 && t1 <= 1) {
            return csg_tree::classification({csg_tree::edge(edge.min, intPoint1)}, edge);
        }
    } else if (intPoint2Inside) {
        // Only intPoint2 is valid
        if (t2 >= 0 && t2 <= 1) {
            return csg_tree::classification({csg_tree::edge(edge.min, intPoint2)}, edge);
        }
    }
    return csg_tree::classification({}, edge); // No valid segment inside
}


std::vector<rt_utils::csg_tree_intersection> cylinder::intersects(const Ray &ray) const {

    std::vector<rt_utils::csg_tree_intersection> intersections;

    glm::vec3 d = ray.direction;
    glm::vec3 o = ray.origin - center;

    float a = d.x * d.x + d.z * d.z;
    float b = 2.0 * (o.x * d.x + o.z * d.z);
    float c = o.x * o.x + o.z * o.z - r*r;

    float discriminant = b*b - 4*a*c;

    if (discriminant >= 0) {
        float sqrtDiscriminant = sqrt(discriminant);
        float t1 = (-b - sqrtDiscriminant) / (2*a);
        float t2 = (-b + sqrtDiscriminant) / (2*a);

        glm::vec3 hit1 = ray.origin + t1 * d;
        glm::vec3 hit2 = ray.origin + t2 * d;

        bool hit1Inside = (hit1.y >= center.y - h/2.0 && hit1.y <= center.y + h/2.0);
        bool hit2Inside = (hit2.y >= center.y - h/2.0 && hit2.y <= center.y + h/2.0);

        if (hit1Inside) {
            glm::vec3 normal1 = glm::normalize(glm::vec3(hit1.x - center.x, 0, hit1.z - center.z));
            intersections.push_back({ t1, hit1, normal1, this->material,  true,  rt_utils::CYLINDER });
        }

        if (hit2Inside) {
            glm::vec3 normal2 = glm::normalize(glm::vec3(hit2.x - center.x, 0, hit2.z - center.z));
            intersections.push_back({ t2, hit2, normal2, this->material,  false,   rt_utils::CYLINDER });
        }
    }

    return intersections;
}
