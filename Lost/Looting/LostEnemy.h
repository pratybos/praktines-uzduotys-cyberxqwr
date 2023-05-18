//
// Created by CyEm on 5/9/2023.
//

#ifndef INFINITY_LOSTENEMY_H
#define INFINITY_LOSTENEMY_H
#include "Lost.h"
#include <string>

using std::string;

class LostEnemy : public Lost {
private:

    int health;
    int maxHealth;
    int damage;
    int expDrop;
    int moneyDrop;
public:

    LostEnemy(string, float, int, int, int, int, int);

    LostEnemy();

    int getHealth();
    void setHealth(int);
    int getMaxHP();
    void takeDamage(int);
    int dealDamage();
    int experienceDrop();
    int currencyDrop();
    string getName();
};


#endif //INFINITY_LOSTENEMY_H
