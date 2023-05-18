//
// Created by CyEm on 5/9/2023.
//

#ifndef INFINITY_LOST_H
#define INFINITY_LOST_H
#include <string>
#include "../Items/Item.h"

using std::string;

class Lost {
protected:

    string name;
    float encounterChance;
public:

    Lost(string, float);
    Lost();

    float getEncCh();

};


#endif //INFINITY_LOST_H
