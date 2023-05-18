//
// Created by CyEm on 5/9/2023.
//

#ifndef INFINITY_WEAPON_H
#define INFINITY_WEAPON_H
#include <string>
#include "../Items/Item.h"

using std::string;


class Weapon : public Item{

public:

    Weapon(string, int, int, int, int, int, int);
    Weapon();

    ~Weapon() override {}

};


#endif //INFINITY_WEAPON_H
