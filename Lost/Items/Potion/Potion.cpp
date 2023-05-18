//
// Created by CyEm on 5/11/2023.
//

#include "Potion.h"
Potion::Potion(string name_, int dmg, int def, int hp, int price_, int quantity_, int id_)
        : Item(name_, dmg, def, hp, price_, quantity_, id_) {

    name = name_;
    damage = dmg;
    defense = def;
    health = hp;
    price = price_;
    quantity = quantity_;
    id = id_;

}

void Potion::setHealing() {
    health = health + (health * 0.5);
}

Potion::Potion() {}
