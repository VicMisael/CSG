//
// Created by Misael on 21/10/2023.
//

#include <glm/geometric.hpp>
#include <glm/exponential.hpp>
#include "sphere.h"

sphere::sphere(const glm::vec3 &center, float radius) : center(center), radius(radius) {}

std::tuple<float, float> get_sphere_uv(const Point3 p) {
    // p: a given point on the sphere of radius one, centered at the origin.
    // u: returned value [0,1] of angle around the Y axis from X=-1.
    // v: returned value [0,1] of angle from Y=-1 to Y=+1.
    //     <1 0 0> yields <0.50 0.50>       <-1  0  0> yields <0.00 0.50>
    //     <0 1 0> yields <0.50 1.00>       < 0 -1  0> yields <0.50 0.00>
    //     <0 0 1> yields <0.25 0.50>       < 0  0 -1> yields <0.75 0.50>

    using namespace Constants;
    constexpr auto f_pi = static_cast<float>(pi);
    const float theta = acos(-p.y);
    const float phi = atan2f(-p.z, p.x) + f_pi;

    const float u = phi / (2 * pi);
    const float v = theta / pi;
    return {u, v};
}



std::optional<intersectionRec> sphere::intersects(const Ray &ray) const {
    const Vector3 ray_direction = ray.direction;
    const float &radius = this->radius;
    const Point3 &center = this->center;
    const Vector3 origin_minus_center = ray.origin - center;
    const float a = glm::dot(ray_direction, ray_direction);
    const float b = 2.0f * glm::dot(origin_minus_center, ray_direction);
    const float c = glm::dot(origin_minus_center, origin_minus_center) - radius * radius;
    const float disc = b * b - 4.0f * a * c;
    if (disc < 0.0f) {
        return {};
    }
    const float t1 = (-b + sqrtf(disc)) / (2.0f * a);
    const float t2 = (-b - sqrtf(disc)) / (2.0f * a);
    const float closest = std::min(t1, t2);
    const Vector3 closestPoint = (ray.point_at(closest));
    const Vector3 normal = normalize(closestPoint - center);
    //const Vector3 normal= (origin_minus_center + closest * ray_direction) / radius;
    const auto [u, v] = get_sphere_uv(normal);
    return intersectionRec{closest, closestPoint, normal, material, u, v};
}

float sphere::getArea() const {
    return 0;
}

std::vector<csg_tree::edge> sphere::classify(const csg_tree::edge edge) {

    const Vector3 ray_direction = edge.max - edge.min;

    const float &radius = this->radius;
    const Point3 &center = this->center;
    const Vector3 origin_minus_center = edge.min - center;
    const float a = glm::dot(ray_direction, ray_direction);
    const float b = 2.0f * glm::dot(origin_minus_center, ray_direction);
    const float c = glm::dot(origin_minus_center, origin_minus_center) - radius * radius;
    const float disc = b * b - 4.0f * a * c;
    if (disc < 0.0f) {
        return {};
    }

    const float t1 = (-b + sqrtf(disc)) / (2.0f * a);
    const float t2 = (-b - sqrtf(disc)) / (2.0f * a);
    const glm::vec3 directionNormalized = glm::normalize(ray_direction);
    std::vector<csg_tree::edge> output;
    if (t1 < t2) {
        output.push_back(csg_tree::edge{edge.min + t1 * directionNormalized, edge.min + directionNormalized * t2});
    }
    output.push_back(csg_tree::edge{edge.min + t2 * directionNormalized, edge.min + directionNormalized * t1});
    return output;
}

void sphere::transform(Matrix4x4 m) {
    VirtualObject::transform(m);
    center = Vector3(m * Vector4(center, 1));
}
