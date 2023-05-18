//
// Created by CyEm on 5/9/2023.
//

#ifndef INFINITY_LEGGINGS_H
#define INFINITY_LEGGINGS_H

#include "../Item.h"

class Leggings : public Item {
private:
public:

    Leggings(string, int, int, int, int, int, int);
    Leggings();

    ~Leggings() override {}
};


#endif //INFINITY_LEGGINGS_H
