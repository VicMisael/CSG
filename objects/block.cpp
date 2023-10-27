//
// Created by Misael on 21/10/2023.
//

#include "block.h"

bool intersects(const Ray &ray, float &t_min, float &t_max, const glm::vec3 &min_, const glm::vec3 &max_) {

    const auto &dir = ray.direction;
    const auto invD = Vector3(1 / dir.x, 1 / dir.y, 1 / dir.z);
    const auto t0s = (min_ - ray.origin) * invD;
    const auto t1s = (max_ - ray.origin) * invD;

    const Vector3 smaller = glm::min(t0s, t1s);
    const Vector3 bigger = glm::max(t0s, t1s);

    t_min = std::max(t_min, std::max(smaller.x, std::max(smaller.y, smaller.z)));
    t_max = std::min(t_max, std::min(bigger.x, std::min(bigger.y, bigger.z)));

    return (t_min < t_max);
}

glm::vec3 getNormal(const glm::vec3 hit_point, const glm::vec3 &min, const glm::vec3 &max) {
    float epsilon = 1e-5f;
    glm::vec3 normal(0, 0, 0);

    if (std::abs(hit_point.x - min.x) < epsilon) normal = glm::vec3(-1, 0, 0);
    else if (std::abs(hit_point.x - max.x) < epsilon) normal = glm::vec3(1, 0, 0);

    if (std::abs(hit_point.y - min.y) < epsilon) normal = glm::vec3(0, -1, 0);
    else if (std::abs(hit_point.y - max.y) < epsilon) normal = glm::vec3(0, 1, 0);

    if (std::abs(hit_point.z - min.z) < epsilon) normal = glm::vec3(0, 0, -1);
    else if (std::abs(hit_point.z - max.z) < epsilon) normal = glm::vec3(0, 0, 1);

    return normal;
}

std::tuple<float, float>
get_uv(const glm::vec3 &hit_point, const glm::vec3 &normal, const glm::vec3 &min, const glm::vec3 &max) {
    float u, v;

    // X axis aligned planes
    if (std::abs(normal.x) > 0.5) {
        u = (hit_point.z - min.z) / (max.z - min.z);
        v = (max.y - hit_point.y) / (max.y - min.y);
        return {u, v};
    }

    // Y axis aligned planes
    if (std::abs(normal.y) > 0.5) {
        u = (hit_point.x - min.x) / (max.x - min.x);
        v = (hit_point.z - min.z) / (max.z - min.z);
        return {u, v};
    }

    // Z axis aligned planes
    if (std::abs(normal.z) > 0.5) {
        u = (hit_point.x - min.x) / (max.x - min.x);
        v = (max.y - hit_point.y) / (max.y - min.y);
        return {u, v};
    }

    return {0, 0}; // Fallback
}


std::optional<intersectionRec> block::intersects(const Ray &ray) const {
    float t_min = -std::numeric_limits<float>::max();;
    float t_max = std::numeric_limits<float>::max();
    if (!::intersects(ray, t_min, t_max, min, max)) {
        return {};
    }
    if (t_min < 0) {
        return {};
    }
    float t_hit = glm::max(0.0f, t_min);
    const auto hitPoint = ray.point_at(t_hit);
    const auto normal = getNormal(hitPoint, min, max);
    const auto [u, v] = get_uv(hitPoint, normal, min, max);
    return intersectionRec{t_hit, hitPoint, normal, this->material, u, v};
}

std::vector<csg_tree::edge> block::classify(csg_tree::edge edge) {
    float t_max = glm::length(edge.max - edge.min);
    float t_min = 0;
    auto toMax = glm::normalize(edge.max - edge.min);
    Ray ray(edge.min, glm::normalize(edge.max - edge.min));
    std::vector<csg_tree::edge> output;
    if (::intersects(ray, t_min, t_max, min, max)) {
        output.push_back(csg_tree::edge{edge.min + t_min * toMax, edge.min + t_max * toMax});
    }
    return output;
}

void block::transform(glm::mat4x4 m) {
    VirtualObject::transform(m);
    min = m * glm::vec4(min, 1);
    max = m * glm::vec4(max, 1);
}

