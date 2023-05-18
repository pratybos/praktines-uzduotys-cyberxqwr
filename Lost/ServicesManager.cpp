//
// Created by CyEm on 5/9/2023.
//

#include "ServicesManager.h"
#include <iostream>
#include <iomanip>

ServicesManager::ServicesManager() {


}

ServicesManager::ServicesManager(int kills_, int deaths_, int achievementsTotal_, int achievementsUnlocked_, int mSp,
                                 int stTaken, int maxLvl, int maxExp, int encounters_){

    kills = kills_;
    deaths = deaths_;
    moneySpent = mSp;
    stepsTaken = stTaken;
    achievementsTotal = achievementsTotal_;
    achievementsUnlocked = achievementsUnlocked_;
    maxLevel = maxLvl;
    maxExperience = maxExp;
    encounters = encounters_;
}

void ServicesManager::increaseKills() {
    kills++;
}

void ServicesManager::increaseDeaths() {
    deaths++;
}

void ServicesManager::increaseEncounters() {
    encounters++;
}

int ServicesManager::getEncounters() {
    return encounters;
}

int ServicesManager::getMaxExperience() {
    return maxExperience;
}

void ServicesManager::setMaxExperience() {
    maxExperience = maxExperience * 2;
}

void ServicesManager::setDifficulty(int diff) {
    difficulty = diff;
}
int ServicesManager::getDifficulty() {
    return difficulty;
}

int ServicesManager::getMSpent() {
    return moneySpent;
}

int ServicesManager::getStTaken() {
    return stepsTaken;
}

int ServicesManager::getMaxLevel() {
    return maxLevel;
}

int ServicesManager::getKills() {
    return kills;
}

int ServicesManager::getDeaths() {
    return deaths;
}

int ServicesManager::getAcUnl() {
    return achievementsUnlocked;
}

void ServicesManager::increaseAcUnl() {
    achievementsUnlocked++;
}

int ServicesManager::getAcTotal() {
    return achievementsTotal;
}

void ServicesManager::increaseSteps() {
    stepsTaken++;
}

void ServicesManager::increaseMoneySpent(int spent) {
    moneySpent += spent;
}