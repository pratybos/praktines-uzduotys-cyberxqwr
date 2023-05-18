//
// Created by CyEm on 5/11/2023.
//

#ifndef INFINITY_SHOP_H
#define INFINITY_SHOP_H

#include "../Items/Item.h"
#include "../Player.h"
#include "../Items/Inventory.h"

class Shop : public Item {
private:

public:

    Shop();

    void listItems();
    void listHats();
    void listChestplates();
    void listLeggings();
    void listBoots();
    void listWeapons();
    void listPotion();
    bool buyItem(Item*, int, Player&, ServicesManager&);
};


#endif //INFINITY_SHOP_H
