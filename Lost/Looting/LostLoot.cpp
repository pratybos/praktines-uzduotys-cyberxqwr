//
// Created by CyEm on 5/9/2023.
//

#include <vector>
#include <cstdlib>
#include <iostream>
#include "LostLoot.h"

LostLoot::LostLoot(string name_, float encCh, std::vector<Item*>& chestContents_, int quantity_) : Lost(name_, encCh){

    name = name_;
    encounterChance = encCh;
    chestContents = chestContents_;
    quantity = quantity_;
}

void LostLoot::decreaseQuantity() {
    quantity--;
}


Item* LostLoot::dropItem() {

    int position = 1 + (rand() % chestContents.size());
    decreaseQuantity();

    return chestContents.at(position - 1);
}

bool LostLoot::operator==(const LostLoot& other) const {

    return name == other.name && encounterChance == other.encounterChance;

}

int LostLoot::getQuantity() {
    return quantity;
}


void LostLoot::increaseQuantity() {
    quantity++;
}

string LostLoot::getName() {
    return name;
}

LostLoot::LostLoot() : Lost() {}

