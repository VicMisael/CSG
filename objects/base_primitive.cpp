//
// Created by Misael on 21/10/2023.
//

#include "base_primitive.h"

#include <utility>

rt_utils::primitive_type base_primitive::get_type() {
    return this->type;
}

void base_primitive::set_material(std::shared_ptr<Material> newMaterial) {
    this->material = std::move(newMaterial);
}
