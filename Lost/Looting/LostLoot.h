//
// Created by CyEm on 5/9/2023.
//

#ifndef INFINITY_LOSTLOOT_H
#define INFINITY_LOSTLOOT_H
#include "Lost.h"
#include "../Items/Item.h"
#include <string>
#include <vector>

using std::string;

class LostLoot : public Lost {
private:

    std::vector <Item*> chestContents;
    int quantity;

public:

    LostLoot(string, float, std::vector <Item*>&, int);

    LostLoot();

    int getQuantity();
    string getName();
    Item* dropItem();
    void increaseQuantity();
    void decreaseQuantity();

    bool operator==(const LostLoot& other) const;

};


#endif //INFINITY_LOSTLOOT_H
