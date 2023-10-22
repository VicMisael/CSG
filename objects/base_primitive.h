//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_BASE_PRIMITIVE_H
#define CSG_BASE_PRIMITIVE_H


#include "../strippedRayTracer/RayTracerRedone/tracer/objects/VirtualObject.h"
#include "../strippedRayTracer/RayTracerRedone/tracer/scene/materials/Phong.h"

class base_primitive : public VirtualObject {
protected:
    base_primitive() : VirtualObject(std::make_shared<Phong>(ColorVec(0.5, 0.5, 0.5), 1, 1, 25)) {}
};


#endif //CSG_BASE_PRIMITIVE_H
