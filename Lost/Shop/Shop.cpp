//
// Created by CyEm on 5/11/2023.
//

#include "Shop.h"
#include "../Items/Inventory.h"
#include <iostream>

Shop::Shop() : Item() {}

void Shop::listHats() {

    std::cout << "------------------------ Shop - Hats ------------------------\n";
    std::cout << std::endl;
    std::cout << "1. Poor man's hat. Stats: 5 damage, 5 defense, 0 health. Price: 15 gold\n";
    std::cout << "2. Somewhat of a hat. Stats: 5 damage, 10 defense, 0 health. Price: 25 gold\n";
    std::cout << "3. Basic hat. Stats: 10 damage, 10 defense, 5 health. Price: 35 gold\n";
    std::cout << "4. Enhanced hat. Stats: 10 damage, 20 defense, 10 health. Price: 50 gold\n";
    std::cout << "5. Wizard's hat [EXTRA HP]. Stats: 20 damage, 30 defense, 40 health. Price: 80 gold\n";
    std::cout << "6. Warrior's hat [EXTRA DEF]. Stats: 20 damage, 40 defense, 20 health. Price: 85 gold\n";
    std::cout << "7. Femboy's hat. Stats: 30 damage, 30 defense, 30 health. Price: 100 gold\n";
    std::cout << "8. Chad's hat [EXTRA STR]. Stats: 50 damage, 30 defense, 20 health. Price: 130 gold\n";
    std::cout << std::endl;
}

void Shop::listChestplates() {

    std::cout << "--------------------- Shop - Chestplates ------------------------\n";
    std::cout << std::endl;
    std::cout << "1. Poor man's jacket. Stats: 2 damage, 5 defense, 0 health. Price: 15 gold\n";
    std::cout << "2. Somewhat of a jacket. Stats: 3 damage, 10 defense, 0 health. Price: 25 gold\n";
    std::cout << "3. Basic jacket. Stats: 5 damage, 15 defense, 0 health. Price: 35 gold\n";
    std::cout << "4. Enhanced jacket. Stats: 10 damage, 20 defense, 5 health. Price: 50 gold\n";
    std::cout << "5. Wizard's jacket. Stats: 15 damage, 20 defense, 20 health. Price: 75 gold\n";
    std::cout << "6. Warrior's chestplate. Stats: 20 damage, 30 defense, 10 health. Price: 80 gold\n";
    std::cout << "7. Femboy's jacket. Stats: 25 damage, 25 defense, 25 health. Price: 100 gold\n";
    std::cout << "8. Chad's armor. Stats: 30 damage, 35 defense, 20 health. Price: 120 gold\n";
    std::cout << std::endl;
}

void Shop::listLeggings() {

    std::cout << "--------------------- Shop - Leggings ------------------------\n";
    std::cout << std::endl;
    std::cout << "1. Poor man's leggings. Stats: 2 damage, 5 defense, 0 health. Price: 15 gold\n";
    std::cout << "2. Somewhat of leggings. Stats: 3 damage, 10 defense, 0 health. Price: 25 gold\n";
    std::cout << "3. Basic leggings. Stats: 5 damage, 15 defense, 0 health. Price: 35 gold\n";
    std::cout << "4. Enhanced leggings. Stats: 10 damage, 20 defense, 5 health. Price: 50 gold\n";
    std::cout << "5. Wizard's leggings. Stats: 15 damage, 20 defense, 20 health. Price: 75 gold\n";
    std::cout << "6. Warrior's leggings. Stats: 20 damage, 30 defense, 10 health. Price: 80 gold\n";
    std::cout << "7. Femboy's leggings. Stats: 25 damage, 25 defense, 25 health. Price: 100 gold\n";
    std::cout << "8. Chad's leggings. Stats: 30 damage, 35 defense, 20 health. Price: 120 gold\n";
    std::cout << std::endl;
}

void Shop::listBoots() {

    std::cout << "--------------------- Shop - Boots ------------------------\n";
    std::cout << std::endl;
    std::cout << "1. Poor man's boots. Stats: 5 damage, 5 defense, 0 health. Price: 15 gold\n";
    std::cout << "2. Somewhat of boots. Stats: 5 damage, 10 defense, 0 health. Price: 25 gold\n";
    std::cout << "3. Basic boots. Stats: 10 damage, 10 defense, 5 health. Price: 35 gold\n";
    std::cout << "4. Enhanced boots. Stats: 10 damage, 20 defense, 10 health. Price: 50 gold\n";
    std::cout << "5. Wizard's boots [EXTRA HP]. Stats: 15 damage, 20 defense, 40 health. Price: 85 gold\n";
    std::cout << "6. Warrior's boots [EXTRA HP]. Stats: 20 damage, 30 defense, 30 health. Price: 90 gold\n";
    std::cout << "7. Femboy's boots. Stats: 30 damage, 30 defense, 30 health. Price: 100 gold\n";
    std::cout << "8. Chad's boots [EXTRA HP]. Stats: 40 damage, 30 defense, 40 health. Price: 130 gold\n";
    std::cout << std::endl;
}

void Shop::listWeapons() {

    std::cout << "-------------------- Shop - Weapons ------------------------\n";
    std::cout << std::endl;
    std::cout << "1. Stick. Stats: 5 damage. Price: 15 gold\n";
    std::cout << "2. Wooden sword. Stats: 7 damage. Price: 25 gold\n";
    std::cout << "3. Spear. Stats: 10 damage. Price: 35 gold\n";
    std::cout << "4. Bow. Stats: 14 damage. Price: 45 gold\n";
    std::cout << "5. Baseball bat. Stats: 17 damage. Price: 55 gold\n";
    std::cout << "6. Wizard's staff. Stats: 23 damage. Price: 65 gold\n";
    std::cout << "7. Warrior's sword. Stats: 30 damage. Price: 90 gold\n";
    std::cout << "8. Femboy's stick. Stats: 35 damage. Price: 105 gold\n";
    std::cout << "9. Chad's greatsword. Stats: 50 damage. Price: 140 gold\n";
    std::cout << std::endl;
}

void Shop::listPotion() {

    std::cout << "-------------------- Shop - Potion ------------------------\n";
    std::cout << std::endl;
    std::cout << "1. Health Potion. Base healing - 50 health (0.5x increase per level). Price: 50 gold\n";
    std::cout << std::endl;
}

bool Shop::buyItem(Item* item_, int q, Player& player_, ServicesManager& tracker_) {

    if(player_.getCurreny() > (item_->getPrice() * q)){

        player_.spentCurreny((item_->getPrice() * q));
        tracker_.increaseMoneySpent((item_->getPrice() * q));
        return true;

    } else{

        std::cout << "You do not have enough money for this purchase.\n";
        return false;
    }
}