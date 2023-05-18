//
// Created by CyEm on 5/10/2023.
//

#ifndef INFINITY_INVENTORY_H
#define INFINITY_INVENTORY_H
#include <vector>
#include "Item.h"
#include "../Looting/LostLoot.h"
#include "Hats/Hat.h"
#include "Chestplates/Chestplate.h"
#include "Leggings/Leggings.h"
#include "Boots/Boots.h"
#include "../Weapon/Weapon.h"
#include "Potion/Potion.h"

using std::vector;


class Inventory {
private:
    vector<Item*> all;
    vector<Item*> hats;
    vector<Item*> chestplates;
    vector<Item*> leggings;
    vector<Item*> boots;
    vector<Item*> potions;
    vector<Item*> weapons;

    vector<LostLoot> chests;

    Item item;
    LostLoot chest;

public:

    Inventory();

    Item* addToInventoryItem(Item* item);
    LostLoot* addToInventoryChest(LostLoot& chest);
    void removeFromInventoryChest(LostLoot&);
    void potionUsed(Potion&);
    void showAll();
    void showHats();
    void showChestplates();
    void showLeggings();
    void showBoots();
    void showPotions();
    void showWeapons();
    void showChests();
    bool checkIfEmpty();
    Hat* getHat(int);
    Chestplate getChestplate(int);
    Leggings getLeggings(int);
    Boots getBoots(int);
    Weapon getWeapon(int);
    LostLoot getChest(int);
    LostLoot* getLostLoot(int);

};


#endif //INFINITY_INVENTORY_H
