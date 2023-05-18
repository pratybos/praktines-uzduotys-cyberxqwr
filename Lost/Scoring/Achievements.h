//
// Created by CyEm on 5/18/2023.
//

#ifndef INFINITY_ACHIEVEMENTS_H
#define INFINITY_ACHIEVEMENTS_H


#include "../ServicesManager.h"
#include "../Player.h"

class Achievements {
private:

    int index;
    int ac[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0};

    vector<string> achievements{"Into the adventure!", "First encounter", "First kill", "Money well spent",
                                "Looking pretty buffed", "Level 5 reached", "Level 10 reached", "Level 15 reached",
                                "Max level reached!", "Lost Slayer", "Travelled 1000 steps across the map!",
                                "First 1000 spent", "A freshly looking hat!", "Summertime jacket", "Pants are needed...",
                                "New shoes", "What a Chad", "Losing is fine too...", "First encounter in Impossible mode",
                                "First kill in Impossible mode", "Ah, a weapon", "Magic in RPG?", "Level 5 in Impossible :o",
                                "Level 10 already???", "Lost conqueror"};
    vector<string> achievementsUnl;

public:

    Achievements();
    void checkAchievements(ServicesManager&, Player&);
    void printAchievement(int);
    void printAll();
};


#endif //INFINITY_ACHIEVEMENTS_H
