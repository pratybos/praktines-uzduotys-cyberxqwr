//
// Created by CyEm on 5/9/2023.
//

#include "Lost.h"

Lost::Lost(string name_, float encounterChance_) {
    name = name_;
    encounterChance = encounterChance_;
}

Lost::Lost() {}

float Lost::getEncCh() {
    return encounterChance;
}

