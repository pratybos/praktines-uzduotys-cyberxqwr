//
// Created by CyEm on 5/9/2023.
//

#ifndef INFINITY_SERVICESMANAGER_H
#define INFINITY_SERVICESMANAGER_H
#include <string>
#include <vector>

using std::string;
using std::vector;


class ServicesManager {

protected:
    int maxLevel;
    int maxExperience;
    int kills;
    int deaths;
    int stepsTaken;
    int moneySpent;
    int encounters;
    int achievementsTotal;
    int achievementsUnlocked;
    int difficulty;

public:

    ServicesManager(int, int, int, int, int, int, int, int, int);

    ServicesManager();


    int getMaxExperience();
    void setMaxExperience();
    int getMaxLevel();
    int getKills();
    int getDeaths();
    int getAcUnl();
    int getAcTotal();

    /* STATS UPDATER */

    void increaseKills();
    void increaseDeaths();
    void increaseSteps();
    void increaseMoneySpent(int);
    void increaseEncounters();
    int getEncounters();
    void setDifficulty(int);
    int getDifficulty();
    int getMSpent();
    int getStTaken();
    void increaseAcUnl();

};


#endif //INFINITY_SERVICESMANAGER_H
