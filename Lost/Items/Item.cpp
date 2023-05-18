//
// Created by CyEm on 5/9/2023.
//

#include "Item.h"

Item::Item(string name_, int dmg, int def, int hp, int price_, int quantity_, int id_) {

    name = name_;
    damage = dmg;
    defense = def;
    health = hp;
    price = price_;
    quantity = quantity_;
    id = id_;
}

Item::Item() {}

Item::Item(string name_, int quantity_) {
    name = name_;
    quantity = quantity_;
}

int Item::getDamage() {
    return damage;
}

int Item::getDefense() {
    return defense;
}

int Item::getHealth() {
    return health;
}

int Item::getPrice() {
    return price;
}

string Item::getName() {
    return name;
}

int Item::getQuantity() {
    return quantity;
}

int Item::getID() {
    return id;
}

void Item::increaseQuantity() {
    quantity++;
}

void Item::decreaseQuantity() {
    quantity--;
}