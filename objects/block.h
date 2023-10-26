//
// Created by Misael on 21/10/2023.
//

#ifndef CSG_BLOCK_H
#define CSG_BLOCK_H


#include "base_primitive.h"

class block: public base_primitive {

public:
    bool classify(csg_tree::edge edge) override;

    std::optional<intersectionRec> intersects(const Ray &ray) const override;



    float getArea() const override;

};


#endif //CSG_BLOCK_H
