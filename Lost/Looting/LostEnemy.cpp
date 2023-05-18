//
// Created by CyEm on 5/9/2023.
//

#include "LostEnemy.h"

LostEnemy::LostEnemy(string name_, float encCh, int hp, int maxHp, int dmg, int expDrop_, int moneyDrop_) : Lost(name_, encCh) {

    name = name_;
    encounterChance = encCh;
    maxHealth = maxHp;
    health = hp;
    damage = dmg;
    expDrop = expDrop_;
    moneyDrop = moneyDrop_;

}

int LostEnemy::getHealth() {
    return health;
}

int LostEnemy::getMaxHP() {
    return maxHealth;
}

int LostEnemy::dealDamage() {
    return damage;
}

void LostEnemy::takeDamage(int dmg) {
    health = health - dmg;
}

void LostEnemy::setHealth(int hp) {
    health = hp;
}

int LostEnemy::experienceDrop() {
    return expDrop;
}

string LostEnemy::getName(){
    return name;
}

int LostEnemy::currencyDrop() {
    return moneyDrop;
}

LostEnemy::LostEnemy() {}
