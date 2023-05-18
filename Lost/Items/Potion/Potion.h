//
// Created by CyEm on 5/11/2023.
//

#ifndef INFINITY_POTION_H
#define INFINITY_POTION_H


#include "../Item.h"

class Potion : public Item {

public:

    Potion(string, int, int, int, int, int, int);

    Potion();

    ~Potion() override {}

    void setHealing();
};


#endif //INFINITY_POTION_H
