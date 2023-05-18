//
// Created by CyEm on 5/12/2023.
//

#include "Interface.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

Interface::Interface() {

}


void Interface::initializeEnemy(LostEnemy enemy_) {
    enemy = enemy_;
}

void Interface::showBottomWhileMap(Player& player) {

    std::cout << "[-------------------- " << player.getName() << " --------------------]  W/A/S/D - Move Up/Left/Down/Right | [B] - Open Inventory | [P] - Open Shop\n";
    std::cout << "| Health: " << player.getHealth() << "/" << player.getMaxHealth() << " / Level: " << player.getLevel() << " / Experience: " << player.getExperience() <<
    "                       [C] - Character | [O] - Stats | [>] - End game\n";
    std::cout << "| Gold: " << player.getCurreny() << std::endl;
}

void Interface::showShopBottom() {
    std::cout << "------------------------------------- SHOP OPTIONS ------------------------------------- \n";
    std::cout << "[1] - View available hats | [2] - View available chestplates | [3] - View available leggings\n";
    std::cout << "[4] - View available boots | [5] - View available weapons | [6] - View available potions\n";
    std::cout << "[P] - Close shop | ";

}

void Interface::fighting(ServicesManager& servicesManager, Player& player, GameWorld& world, Potion& potion, Inventory& inventory) {

    char input;

    bool fight = true;

    while (fight) {

        system("cls");

        std::cout << "__________ " << player.getName() << " vs " << enemy.getName() << " __________\n";
        std::cout << std::endl;
        std::cout << player.getName() << "'s health: " << player.getHealth() << "/" << player.getMaxHealth() << std::endl;
        std::cout << enemy.getName() << "'s health: " << enemy.getHealth() << std::endl;

        std::cout << std::endl;
        std::cout << "__________ FIGHT OPTIONS __________\n";
        std::cout << "Flee [F] | Attack [A] | Use potion [P]\n";
        std::cout << std::endl;
        std::cin >> input;
        if (input == 'a' || input == 'A') {
            enemy.takeDamage(player.dealDamage());

            std::cout << "You have dealt " << player.dealDamage() << " damage.\n";

            if (enemy.getHealth() <= 0){

                std::cout << "You have won the battle.\n";
                servicesManager.increaseKills();
                player.setExperience(enemy.experienceDrop(), servicesManager, potion);
                std::cout << "You have received " << enemy.currencyDrop() << " gold.\n";
                player.setCurrency(enemy.currencyDrop());
                fight = false;
                break;

            }
            player.takeDamage(enemy.dealDamage());

            std::cout << enemy.getName() << " dealt " << enemy.dealDamage() << std::endl;

            if (player.getHealth() <= 0) {

                std::cout << "\nHappens to the best of us...\n";
                servicesManager.increaseDeaths();
                player.flee();
                world.playerFled();
                player.setHealth(player.getMaxHealth());
                fight = false;
                break;

            }

            getch();

        }   else if (input == 'f' || input == 'F') {

            servicesManager.increaseDeaths();
            player.flee();

            if (player.getHealth() == 0) {

                std::cout << "You have died while fleeing...\n";
                world.playerFled();
                break;
            }

            world.playerFled();

            std::cout << "You have fled. A coward or a smart-man?\n";


            fight = false;

        }   else if (input == 'p' || input == 'P'){

            player.usePotion(potion, inventory);
            getch();

        }   else std::cout << "\nNo such option.\n";

    }
}

void Interface::showStats(ServicesManager& servicesManager, Player& player, Achievements& achievements) {

    float kda = (float)servicesManager.getKills() / (float)servicesManager.getDeaths();

    std::cout << "------------------------ " << player.getName() << " ------------------------\n";
    std::cout << std::endl;
    std::cout << "Level: " << player.getLevel() << "/" << servicesManager.getMaxLevel() << std::endl;;
    std::cout << "Experience: " << player.getExperience() << "/" << servicesManager.getMaxExperience() << std::endl;;
    std::cout << "Health: " << player.getHealth() << "/" << player.getMaxHealth() << std::endl;
    std::cout << "Damage: " << player.getDamage() << std::endl;
    std::cout << "Defense: " << player.getDefense() << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------ Stats Tracker ------------------------\n";
    std::cout << std::endl;
    std::cout << "Kills: " << servicesManager.getKills() << std::endl;;
    std::cout << "Deaths: " << servicesManager.getDeaths() << std::endl;;
    std::cout << "K/DA: " << std::setprecision(3) << kda << std::endl;;
    std::cout << "Achievements unlocked: " << servicesManager.getAcUnl() << "/" << servicesManager.getAcTotal() << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------ Achievements ------------------------\n";
    std::cout << std::endl;
    achievements.printAll();

}

void Interface::showInventoryBottom() {
    std::cout << "-------------------------------- INVENTORY OPTIONS --------------------------------\n";
    std::cout << "[1] - View all items | [2] - View hats | [3] - View chestplates | [4] - View leggings\n";
    std::cout << "[5] - View boots | [6] - View weapons | [7] - View potions | [8] - View chests\n";
    std::cout << "[B] - Close inventory |";

}

void Interface::showCharacter(Player& player) {

    std::cout << "--------------------------------" << player.getName() << "--------------------------------\n";
    std::cout << std::endl;
    std::cout << "Currently equipped:\n";
    std::cout << "Hat: " << player.getHat().getName() << std::endl;
    std::cout << "Chestplate: " << player.getChestplate().getName() << std::endl;
    std::cout << "Leggings: " << player.getLeggings().getName() << std::endl;
    std::cout << "Boots: " << player.getBoots().getName() << std::endl;
    std::cout << "Weapon: " << player.getWeapon().getName() << std::endl;
    std::cout << std::endl;
    std::cout << "Ability points available: " << player.getAP() << std::endl;

}

void Interface::showAbilityBottomAP() {

    std::cout << "----------------------------------- Character Options -----------------------------------\n";
    std::cout << std::endl;
    std::cout << "[1] - increase damage | [2] - increase defense | [3] - increase max health | [C] - close\n";
}

void Interface::showAbilityBottomNoAP() {

    std::cout << "-------------------------------- Character Options --------------------------------\n";
    std::cout << std::endl;
    std::cout << "[C] - close\n";
}
