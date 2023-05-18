//
// Created by CyEm on 5/8/2023.
//

#ifndef INFINITY_PLAYER_H
#define INFINITY_PLAYER_H

#include <string>
#include "ServicesManager.h"
#include "Items/Hats/Hat.h"
#include "Items/Chestplates/Chestplate.h"
#include "Items/Leggings/Leggings.h"
#include "Items/Boots/Boots.h"
#include "Weapon/Weapon.h"
#include "Items/Potion/Potion.h"
#include "Looting/LostLoot.h"
#include "Items/Inventory.h"


class Player {
protected:

    std::string playerName;

    /* stats */
    int Dmg;
    int Def;
    int playerLevel;
    int playerExperience;
    int abilityPoint;
    int health;
    int maxHealth;
    int currency;
    Hat hat;
    Chestplate chestplate;
    Leggings leggings;
    Boots boots;
    Weapon weapon;

public:

    Player(string, int, int, int, int, int, int, int, int);

    Player();

    /* EQUIP */

    void setHat(Hat* hat);
    Hat getHat();
    void setChestplate(Chestplate chestplate);
    Chestplate getChestplate();
    void setLeggings(Leggings leggings);
    Leggings getLeggings();
    void setBoots(Boots boots);
    Boots getBoots();
    void setWeapon(Weapon weapon);
    Weapon getWeapon();

    /* UNEQUIP */

    void removeHat();
    void removeChestplate();
    void removeLeggings();
    void removeBoots();
    void removeWeapons();

    /* SERVICE MANAGER */

    int getLevel();
    int getExperience();
    void setExperience(int, ServicesManager&, Potion&);

    /* STATS */

    void increaseDamage();
    void increaseDefense();
    void increaseHealth();
    int getAP();
    void increaseAP();
    string getName();
    int getDamage();
    int getDefense();

    /* FIGHTING */

    int getMaxHealth();
    int getHealth();
    void setHealth(int);
    void takeDamage(int);
    int dealDamage();
    void flee();

    /* INVENOTRY/SHOP PLAYER FUNCTIONALITY */

    void usePotion(Potion&, Inventory&);
    int getCurreny();
    void setCurrency(int);
    void spentCurreny(int);

};


#endif //INFINITY_PLAYER_H
