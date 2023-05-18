//
// Created by CyEm on 5/18/2023.
//

#include <conio.h>
#include <iostream>
#include "Achievements.h"

Achievements::Achievements() {


}

void Achievements::checkAchievements(ServicesManager& servicesManager, Player& player) {

    if(ac[0] == 0){

        ac[0] = 1;
        servicesManager.increaseAcUnl();
        index = 0;
        printAchievement(index);
    }

    if(ac[1] == 0 && servicesManager.getEncounters() > 0){

        ac[1] = 1;
        index = 1;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[2] == 0 && servicesManager.getKills() > 0){

        ac[2] = 1;
        index = 2;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[3] == 0 && servicesManager.getMSpent() > 0){

        ac[3] = 1;
        index = 3;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[4] == 0 && player.getDamage() >= 20){

        ac[4] = 1;
        index = 4;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[5] == 0 && player.getLevel() == 5){

        ac[5] = 1;
        index = 5;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[6] == 0 && player.getLevel() == 10){

        ac[6] = 1;
        index = 6;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[7] == 0 && player.getLevel() == 15){

        ac[7] = 1;
        index = 7;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[8] == 0 && player.getLevel() == 20){

        ac[8] = 1;
        index = 8;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[9] == 0 && servicesManager.getKills() >= 20){

        ac[9] = 1;
        index = 9;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[10] == 0 && servicesManager.getStTaken() >= 1000){

        ac[10] = 1;
        index = 10;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[11] == 0 && servicesManager.getMSpent() >= 1000){

        ac[11] = 1;
        index = 11;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[12] == 0 && player.getHat().getName() != "None"){

        ac[12] = 1;
        index = 12;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[13] == 0 && player.getChestplate().getName() != "None"){

        ac[13] = 1;
        index = 13;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[14] == 0 && player.getLeggings().getName() != "None"){

        ac[14] = 1;
        index = 14;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[15] == 0 && player.getBoots().getName() != "None"){

        ac[15] = 1;
        index = 15;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[16] == 0 && player.getWeapon().getName() == "Chad's greatsword"){

        ac[16] = 1;
        index = 16;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[17] == 0 && servicesManager.getDeaths() == 1){

        ac[17] = 1;
        index = 17;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[18] == 0 && servicesManager.getDifficulty() == 4 && servicesManager.getEncounters() == 1){

        ac[18] = 1;
        index = 18;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[19] == 0 && servicesManager.getDifficulty() == 4 && servicesManager.getKills() == 1){

        ac[19] = 1;
        index = 19;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[20] == 0 && player.getWeapon().getName() != "None"){

        ac[20] = 1;
        index = 20;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[21] == 0 && player.getWeapon().getName() == "Wizard's staff"){

        ac[21] = 1;
        index = 21;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[22] == 0 && servicesManager.getDifficulty() == 4 && player.getLevel() == 5){

        ac[22] = 1;
        index = 22;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[23] == 0 && servicesManager.getDifficulty() == 4 && player.getLevel() == 10){

        ac[23] = 1;
        index = 23;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }

    if(ac[24] == 0 && servicesManager.getDifficulty() == 4 && player.getLevel() == 20){

        ac[24] = 1;
        index = 24;
        servicesManager.increaseAcUnl();
        printAchievement(index);
    }
}

void Achievements::printAchievement(int i) {

    system("cls");
    std::cout << "[---------- Achievement Unlocked ----------]\n";
    std::cout << std::endl;
    std::cout << "            " << achievements.at(i) << std::endl;
    std::cout << std::endl;
    std::cout << "[ ________________________________________ ]\n";
    getch();

}

void Achievements::printAll() {

    for (int i = 0; i < achievements.size(); i++){

        if (ac[i] == 0){

            std::cout << achievements.at(i) << " - Locked\n";
        }   else std::cout << achievements.at(i) << " - Unlocked\n";
    }
}