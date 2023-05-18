#include <iostream>
#include "Player.h"

Player::Player(string name_, int dmg, int def, int hp, int maxHp, int ap, int lvl, int exp, int cur) {

    playerName = name_;
    Dmg = dmg;
    Def = def;
    playerLevel = lvl;
    playerExperience = exp;
    currency = cur;
    health = hp;
    maxHealth = maxHp;
    abilityPoint = ap;
}

Player::Player() {}

/* ATTRIBUTES */

void Player::increaseAP() {

    abilityPoint++;
}

void Player::setHat(Hat* hat_) {
    hat = *hat_;
    Dmg += hat.getDamage();
    Def += hat.getDefense();
    maxHealth += hat.getHealth();

}

void Player::removeHat() {
    Dmg -= hat.getDamage();
    Def -= hat.getDefense();
    maxHealth -= hat.getHealth();
    hat = Hat();
}

Hat Player::getHat() {
    return hat;
}

void Player::setChestplate(Chestplate chestplate_) {
    chestplate = chestplate_;
    Dmg += chestplate.getDamage();
    Def += chestplate.getDefense();
    maxHealth += chestplate.getHealth();
}

Chestplate Player::getChestplate() {
    return chestplate;
}

void Player::removeChestplate() {
    Dmg -+ chestplate.getDamage();
    Def -= chestplate.getDefense();
    maxHealth -= chestplate.getHealth();
}

void Player::setLeggings(Leggings leggings_) {
    leggings = leggings_;
    Dmg += leggings.getDamage();
    Def += leggings.getDefense();
    maxHealth += leggings.getHealth();
}

Leggings Player::getLeggings() {
    return leggings;
}

void Player::removeLeggings() {
    Dmg -+ leggings.getDamage();
    Def -= leggings.getDefense();
    maxHealth -= leggings.getHealth();
}

void Player::setBoots(Boots boots_) {
    boots = boots_;
    Dmg += boots.getDamage();
    Def += boots.getDefense();
    maxHealth += boots.getHealth();
}

Boots Player::getBoots() {
    return boots;
}

void Player::removeBoots() {
    Dmg -+ boots.getDamage();
    Def -= boots.getDefense();
    maxHealth -= boots.getHealth();
}

void Player::setWeapon(Weapon weapon_) {
    weapon = weapon_;
    Dmg += weapon.getDamage();
    Def += weapon.getDefense();
    maxHealth += weapon.getHealth();
}

Weapon Player::getWeapon() {
    return weapon;
}

void Player::removeWeapons() {
    Dmg -+ weapon.getDamage();
    Def -= weapon.getDefense();
    maxHealth -= weapon.getHealth();
}

/* SERVICE MANAGER */

int Player::getLevel() {
    return playerLevel;
}

int Player::getExperience() {
    return playerExperience;
}

void Player::setExperience(int exp, ServicesManager& servicesManager, Potion& potion) {
    playerExperience = playerExperience + exp;

    std::cout << "You have received " << exp << " experience.\n";

    if (playerExperience >= servicesManager.getMaxExperience()) {
        playerLevel++;
        abilityPoint++;
        health = maxHealth;
        potion.setHealing();
        std::cout << "Your level has been increased to " << playerLevel << std::endl;
        playerExperience -= servicesManager.getMaxExperience();
        servicesManager.setMaxExperience();
    }
}

/* FIGHTING */

int Player::getHealth() {
    return health;
}

int Player::getMaxHealth() {
    return maxHealth;
}

int Player::dealDamage() {
    return Dmg;
}

void Player::takeDamage(int dmg) {
    health = health - (dmg - (Def * 0.5));
}

void Player::usePotion(Potion& potion, Inventory& inventory) {

    if (potion.getQuantity() > 0){

        if (health + potion.getHealth() < maxHealth){

            health = health + potion.getHealth();
            inventory.potionUsed(potion);
            std::cout << "You have used a potion.\n";
        }   else if (health != maxHealth && health + potion.getHealth() >= maxHealth) {

            health = maxHealth;
            inventory.potionUsed(potion);
            std::cout << "You have used a potion.\n";
        }   else std::cout << "You already have maximum health.\n";
    } else std::cout << "You do not have a potion to use.\n";

}

void Player::increaseDamage() {

    Dmg += 5;
    abilityPoint -= 1;
}

void Player::increaseDefense() {

    Def += 5;
    abilityPoint -= 1;
}

void Player::increaseHealth() {

    maxHealth += 5;
    abilityPoint -= 1;
}

int Player::getAP() {
    return abilityPoint;
}

string Player::getName() {
    return playerName;
}

int Player::getDamage() {
    return Dmg;
}

int Player::getDefense() {
    return Def;
}

int Player::getCurreny() {
    return currency;
}

void Player::setHealth(int hp) {
    health = hp;
}

void Player::setCurrency(int got) {
    currency += got;
}

void Player::spentCurreny(int spent) {
    currency -= spent;
}

void Player::flee() {
    health = health / 2;
    if (playerExperience - (20*playerLevel) > 0){

        playerExperience = playerExperience - (20*playerLevel);
        std::cout << "Oh, by the way, you lost " << playerExperience << " experience. Good luck!\n";
    }
}