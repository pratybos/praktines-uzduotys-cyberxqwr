#include <iostream>
#include "GameWorld.h"
#include "Lost/Player.h"
#include "Lost/Interfaces/Interface.h"
#include <windows.h>
#include <random>
#include <conio.h>
#include <cstring>

LostLoot whatChest(LostLoot weaponChest_, LostLoot commonChest_, LostLoot uncommonChest_, LostLoot rareChest_,
                   LostLoot ultraRareChest_) {

    std::random_device r;

    std::default_random_engine el(r());
    std::uniform_real_distribution<float> chance_dist(0, 1);

    float chance = chance_dist(el);

    if (chance >= 0.894 && chance < 1) {

        std::cout << "\nThe chest found is " << weaponChest_.getName() << std::endl;
        return weaponChest_;
    } else if (chance >= 0.664 && chance < 0.894) {

        std::cout << "\nThe chest found is " << commonChest_.getName() << std::endl;
        return commonChest_;
    } else if (chance >= 0.187 && chance < 0.664) {

        std::cout << "\nThe chest found is " << uncommonChest_.getName() << std::endl;
        return uncommonChest_;
    } else if (chance >= 0.022 && chance < 0.187) {

        std::cout << "\nThe chest found is " << rareChest_.getName() << std::endl;
        return rareChest_;
    } else if (chance >= 0 && chance < 0.022) {

        std::cout << "\nThe chest found is " << ultraRareChest_.getName() << std::endl;
        return ultraRareChest_;

    }
}

LostEnemy whatEnemy(LostEnemy bunny_, LostEnemy weakling_, LostEnemy wolf_, LostEnemy goofball_, LostEnemy bear_,
                    LostEnemy strangler_, LostEnemy madman_, LostEnemy rhino_, LostEnemy craber_, LostEnemy predator_,
                    LostEnemy apex_, LostEnemy rip_) {

    std::random_device r;

    std::default_random_engine el(r());
    std::uniform_real_distribution<float> chance_dist(0, 1);

    float chance = chance_dist(el);

    if (chance >= 0.875 && chance < 1) {

        return bunny_;
    } else if (chance >= 0.754 && chance < 0.875) {

        return weakling_;
    } else if (chance >= 0.684 && chance < 0.754) {

        return wolf_;
    } else if (chance >= 0.634 && chance < 0.684) {

        return goofball_;
    } else if (chance >= 0.543 && chance < 0.634) {

        return bear_;
    } else if (chance >= 0.465 && chance < 0.543) {

        return strangler_;
    } else if (chance >= 0.432 && chance < 0.465) {

        return madman_;
    } else if (chance >= 0.321 && chance < 0.432) {

        return rhino_;
    } else if (chance >= 0.265 && chance < 0.321) {

        return craber_;
    } else if (chance >= 0.153 && chance < 0.265) {

        return predator_;
    } else if (chance >= 0.050 && chance < 0.153) {

        return apex_;
    } else if (chance >= 0 && chance < 0.050) {

        return rip_;
    }
}

int main() {

    // Variables

    /* console */

    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);

    /* shop */

    int quantity;
    int itemNum;

    /* difficulty settings */

    int choiceD;
    float difficulty = 0;

    /* encounter chances */

    float chestOrEnemy;

    LostLoot foundChest;
    LostEnemy enemy;

    /* game engine */

    char input;
    bool difChoice;
    char prevInput;
    int equipChoice;
    bool check;
    bool inventoryOpen;
    bool shopOpen;
    bool statsOpen;
    bool characterOpen;
    bool userBuying;

    // INITIALIZE GAME

    /* default services */

    GameWorld world;
    ServicesManager *tracker = new ServicesManager(0, 0, 25, 0, 0,0, 20, 100, 0); // kills, deaths, achievTotal,
                                                                                // achievUnl, moneySpent, stepsTaken,
                                                                                // encounters
    Shop shop;
    Inventory inventory;
    Interface intf;
    Achievements achievements;

    /* potion */

    Potion *potion = new Potion("Health potion", 0, 0, 50, 50, 0, 5); //

    /* weapons */

    Weapon *noneW = new Weapon("None", 0, 0, 0, 0, 0, 6); // name, dmg, def, health, price, quantity, id
    Weapon *stick = new Weapon("Stick", 5, 0, 0, 15, 0, 6);
    Weapon *woodenSword = new Weapon("Wooden Sword", 7, 0, 0, 25, 0, 6);
    Weapon *spear = new Weapon("Spear", 10, 0, 0, 35, 0, 6);
    Weapon *bow = new Weapon("Bow", 14, 0, 0, 45, 0, 6);
    Weapon *bBat = new Weapon("Baseball Bat", 17, 0, 0, 55, 0, 6);
    Weapon *wStaff = new Weapon("Wizard's staff", 23, 0, 0, 65, 0, 6);
    Weapon *warriorSword = new Weapon("Warrior's sword", 30, 0, 0, 90, 0, 6);
    Weapon *femboyStick = new Weapon("Femboy's stick", 35, 0, 0, 105, 0, 6);
    Weapon *chadSword = new Weapon("Chad's greatsword", 50, 0, 0, 140, 0, 6);

    /* hats */

    Hat *noneH = new Hat("None", 0, 0, 0, 0, 0, 1); // name, dmg, def, health, price, quantity, id
    Hat *poorHat = new Hat("Poor man's hat", 5, 5, 0, 15, 0, 1);
    Hat *someHat = new Hat("Somewhat of a hat", 5, 10, 0, 25, 0, 1);
    Hat *basicHat = new Hat("Basic hat", 10, 10, 5, 35, 0, 1);
    Hat *enhancedHat = new Hat("Enhanced hat", 10, 20, 10, 50, 0, 1);
    Hat *wizardHat = new Hat("Wizard's hat [EXTRA HP]", 20, 30, 40, 80, 0, 1);
    Hat *warriorHat = new Hat("Warrior's hat [EXTRA DEF]", 20, 40, 20, 85, 0, 1);
    Hat *femboyHat = new Hat("Femboy's hat", 30, 30, 30, 100, 0, 1);
    Hat *chadHat = new Hat("Chad's hat [EXTRA DMG]", 50, 30, 20, 130, 0, 1);

    /* chestplates */

    Chestplate *noneC = new Chestplate("None", 0, 0, 0, 0, 0, 2);   // name, dmg, def, health, price, quantity, id
    Chestplate *poorChestplate = new Chestplate("Poor man's jacket", 2, 5, 0, 15, 0, 2);
    Chestplate *someChestplate = new Chestplate("Somewhat of a jacket", 3, 10, 0, 25, 0, 2);
    Chestplate *basicChestplate = new Chestplate("Basic jacket", 5, 15, 0, 35, 0, 2);
    Chestplate *enhancedChestplate = new Chestplate("Enhanced jacket", 10, 20, 5, 50, 0, 2);
    Chestplate *wizardChestplate = new Chestplate("Wizard's jacket", 15, 20, 20, 75, 0, 2);
    Chestplate *warriorChestplate = new Chestplate("Warrior's chestplate", 20, 30, 10, 80, 0, 2);
    Chestplate *femboyChestplate = new Chestplate("Femboy's jacket", 25, 25, 25, 100, 0, 2);
    Chestplate *chadChestplate = new Chestplate("Chad's armor", 30, 35, 20, 120, 0, 2);

    /* leggings */

    Leggings *noneL = new Leggings("None", 0, 0, 0, 0, 0, 3);   // name, dmg, def, health, price, quantity, id
    Leggings *poorLeggings = new Leggings("Poor man's leggings", 2, 5, 0, 15, 0, 3);
    Leggings *someLeggings = new Leggings("Somewhat of leggings", 3, 10, 0, 25, 0, 3);
    Leggings *basicLeggings = new Leggings("Basic leggings", 5, 15, 0, 35, 0, 3);
    Leggings *enhancedLeggings = new Leggings("Enhanced leggings", 10, 20, 5, 50, 0, 3);
    Leggings *wizardLeggings = new Leggings("Wizard's leggings", 15, 20, 20, 75, 0, 3);
    Leggings *warriorLeggings = new Leggings("Warrior's leggings", 20, 30, 10, 80, 0, 3);
    Leggings *femboyLeggings = new Leggings("Femboy's leggings", 25, 25, 25, 100, 0, 3);
    Leggings *chadLeggings = new Leggings("Chad's leggings", 30, 35, 20, 120, 0, 3);

    /* boots */

    Boots *noneB = new Boots("None", 0, 0, 0, 0, 0, 4); // name, dmg, def, health, price, quantity, id
    Boots *poorBoots = new Boots("Poor man's boots", 5, 5, 0, 15, 0, 4);
    Boots *someBoots = new Boots("Somewhat of boots", 5, 10, 0, 25, 0, 4);
    Boots *basicBoots = new Boots("Basic boots", 10, 10, 5, 35, 0, 4);
    Boots *enhancedBoots = new Boots("Enhanced boots", 10, 20, 10, 50, 0, 4);
    Boots *wizardBoots = new Boots("Wizard's boots [EXTRA HP]", 15, 20, 40, 85, 0, 4);
    Boots *warriorBoots = new Boots("Warrior's boots [EXTRA HP]", 20, 30, 30, 90, 0, 4);
    Boots *femboyBoots = new Boots("Femboy's boots", 30, 30, 30, 100, 0, 4);
    Boots *chadBoots = new Boots("Chad's boots [EXTRA HP]", 40, 30, 40, 130, 0, 4);

    /* chest contents */

    vector<Item*> commonContents{poorHat, someHat, poorChestplate, someChestplate, poorLeggings, someLeggings,
                                poorBoots, someBoots};

    vector<Item*> uncommonContents{basicHat, enhancedHat, basicChestplate, enhancedChestplate, basicLeggings,
                                  enhancedLeggings, basicBoots, enhancedBoots};

    vector<Item*> rareContents{femboyHat, wizardChestplate, femboyChestplate, warriorChestplate, chadChestplate,
                              femboyBoots, warriorLeggings};

    vector<Item*> ultraContents{enhancedHat, wizardHat, warriorHat, chadHat, wizardChestplate, femboyLeggings,
                               enhancedBoots, wizardBoots, warriorBoots, chadBoots, chadLeggings,
                               wizardLeggings};

    vector<Item*> weaponContents{stick, woodenSword, spear, bow, bBat, wStaff, warriorSword, femboyStick,
                                chadSword};

    /* chests */

    LostLoot weapons("Weapons Loot Chest", 0.894, weaponContents, 0);
    LostLoot common("Common Loot Chest", 0.775, commonContents, 0);
    LostLoot uncommon("Uncommon Loot Chest", 0.564, uncommonContents, 0);
    LostLoot rare("Rare Loot Chest", 0.2, rareContents, 0);
    LostLoot urare("Ultra Rare Loot Chest", 0.02, ultraContents, 0);

    /* shop containers */

    vector<Item*> hatsShop {poorHat, someHat, basicHat, enhancedHat, wizardHat, warriorHat, femboyHat, chadHat};
    vector<Item*> chestplatesShop {poorChestplate, someChestplate, basicChestplate, enhancedChestplate,
                              wizardChestplate, warriorChestplate, femboyChestplate, chadChestplate};
    vector<Item*> leggingsShop {poorLeggings, someLeggings, enhancedLeggings, wizardLeggings, warriorLeggings,
                           femboyLeggings, chadLeggings};
    vector<Item*> bootsShop {poorBoots, someBoots, enhancedBoots, wizardBoots, warriorBoots, femboyBoots,
                            chadBoots};
    vector<Item*> weaponShop {stick, woodenSword, spear, bow, bBat, wStaff, warriorSword, femboyStick,
                             chadSword};

    // NEW GAME

    /* setting player */

    std::cout << "Welcome to Lost RPG - Let the adventures begin!\n";
    std::cout << "\nWhat is your name (the name should not be longer than 12 characters)?\n";

    string name;
    std::cin >> name;
    std::cout << std::endl;

    std::cout << "\nThank you for joining us, " << name << ". We hope you have an amazing time.\n";
    std::cout << std::endl;
    Player *player = new Player(name, 5, 5, 100, 100, 0, 0, 0, 100); // name, damage, def, hp, maxhp, level, exp, ap
    player->setWeapon(*noneW);
    player->setHat(noneH);
    player->setChestplate(*noneC);
    player->setLeggings(*noneL);
    player->setBoots(*noneB);

    /* setting difficulty settings, map generating */

    world.setUpInitial(45, 200);

    difChoice = true;

    std::cout << "Choose a difficulty\n";
    std::cout << "1. Easy\n2. Normal\n3. Hard\n4. Impossible\n";

    while(difChoice) {
        std::cin >> choiceD;
        tracker->setDifficulty(choiceD);

        switch (choiceD) {
            case 1:
                difficulty = 1;
                world.setUpLostPos(1);
                difChoice = false;
                break;
            case 2:
                difficulty = 1.5;
                world.setUpLostPos(2);
                difChoice = false;
                break;
            case 3:
                difficulty = 2;
                world.setUpLostPos(3);
                difChoice = false;
                break;
            case 4:
                difficulty = 3.5;
                world.setUpLostPos(4);
                difChoice = false;
                break;
            default:
                std::cout << "Wrong choice, enter again.\n";
        }
    }

    world.setPlayerLoc();

    /* setting enemies per difficulty */

    LostEnemy *bunny = new LostEnemy("Bunny", 0.923, (float) 5 * difficulty, (float) 5 * difficulty, (float) 1 * difficulty, (float) 5 * difficulty,
                                     10 * difficulty);
    LostEnemy *weakling = new LostEnemy("Weakling", 0.835, (float) 10 * difficulty, (float) 10 * difficulty, (float) 10 * difficulty,
                                        (float) 15 * difficulty, (float) 20 * difficulty);
    LostEnemy *wolf = new LostEnemy("Wolf", 0.754, (float) 20 * difficulty, (float) 20 * difficulty, (float) 15 * difficulty, (float) 30 * difficulty,
                                    30 * difficulty);
    LostEnemy *goofball = new LostEnemy("Goofball", 0.684, (float) 25 * difficulty, (float) 25 * difficulty, (float) 20 * difficulty,
                                        (float) 35 * difficulty, (float) 35 * difficulty);
    LostEnemy *bear = new LostEnemy("Bear", 0.634, (float) 50 * difficulty, (float) 50 * difficulty, (float) 23 * difficulty, (float) 50 * difficulty,
                                    (float) 40 * difficulty);
    LostEnemy *strangler = new LostEnemy("Strangler", 0.543, (float) 100 * difficulty, (float) 100 * difficulty, (float) 25 * difficulty,
                                         (float) 55 * difficulty, (float) 50 * difficulty);
    LostEnemy *madman = new LostEnemy("Madman", 0.465, (float) 120 * difficulty, (float) 120 * difficulty, (float) 30 * difficulty,
                                      (float) 65 * difficulty, (float) 60 * difficulty);
    LostEnemy *rhino = new LostEnemy("Rhino", 0.432, (float) 140 * difficulty, (float) 140 * difficulty, (float) 40 * difficulty,
                                     (float) 76 * difficulty, (float) 69 * difficulty);
    LostEnemy *craber = new LostEnemy("Craber", 0.321, (float) 160 * difficulty, (float) 160 * difficulty, (float) 48 * difficulty,
                                      (float) 89 * difficulty, (float) 77 * difficulty);
    LostEnemy *predator = new LostEnemy("Predator", 0.265, (float) 180 * difficulty, (float) 180 * difficulty, (float) 56 * difficulty,
                                        (float) 102 * difficulty, (float) 94 * difficulty);
    LostEnemy *apex = new LostEnemy("Apex", 0.153, (float) 200 * difficulty, (float) 200 * difficulty, (float) 69 * difficulty,
                                    (float) 131 * difficulty, (float) 123 * difficulty);
    LostEnemy *rip = new LostEnemy("RIP", 0.265, (float) 300 * difficulty, (float) 300 * difficulty, (float) 99 * difficulty, (float) 230 * difficulty,
                                   (float) 205 * difficulty);

    // INITIALIZING DONE

    system("cls");

    inventory.addToInventoryItem(potion);
    inventory.addToInventoryItem(potion);
    inventory.addToInventoryItem(potion);
    player->increaseAP();
    player->increaseAP();
    player->increaseAP();
    player->increaseAP();

    while (true) {

        achievements.checkAchievements(*tracker, *player);

        system("cls");

        std::cout << std::endl;
        world.printMap();
        std::cout << std::endl;

        SetConsoleTextAttribute(col, 7);

        intf.showBottomWhileMap(*player);
        std::cin >> input;

        if (input == 'w' || input == 'W') { // move up

            check = world.playerMoveUp();
            tracker->increaseSteps();
            if (check && world.getPlayerY() > 0) {

                std::random_device r;

                std::default_random_engine el(r());
                std::uniform_real_distribution<float> chance_dist(0, 1);

                chestOrEnemy = chance_dist(el);
                if (chestOrEnemy < 0.3) {

                    system("cls");
                    std::cout << "Congratulations, a Lost Chest has been found.\n";
                    foundChest = whatChest(weapons, common, uncommon, rare, urare);
                    LostLoot *updatedChest = inventory.addToInventoryChest(foundChest);
                    if (updatedChest != nullptr) {

                        updatedChest->increaseQuantity(); // Update the quantity of the returned chest object
                    }

                    getch();
                } else {

                    tracker->increaseEncounters();
                    system("cls");
                    std::cout << "Enemy enountered!!!\n";
                    enemy = whatEnemy(*bunny, *weakling, *wolf, *goofball,
                                      *bear, *strangler, *madman, *rhino,
                                      *craber, *predator, *apex, *rip);
                    intf.initializeEnemy(enemy);
                    intf.fighting(*tracker, *player, world, *potion, inventory);
                    getch();
                }

            } else {

                // player does nothing

            }
        } else if (input == 'a' || input == 'A') { // move left

            check = world.playerMoveLeft();
            tracker->increaseSteps();
            if (check && world.getPlayerX() > 0) {

                std::random_device r;

                std::default_random_engine el(r());
                std::uniform_real_distribution<float> chance_dist(0, 1);

                chestOrEnemy = chance_dist(el);
                if (chestOrEnemy < 0.3) {

                    system("cls");
                    std::cout << "Congratulations, a Lost Chest has been found.\n";
                    foundChest = whatChest(weapons, common, uncommon, rare, urare);
                    LostLoot *updatedChest = inventory.addToInventoryChest(foundChest);
                    if (updatedChest != nullptr) {
                        updatedChest->increaseQuantity(); // Update the quantity of the returned chest object
                    }

                    getch();

                } else {

                    tracker->increaseEncounters();
                    system("cls");
                    std::cout << "Enemy enountered!!!\n";
                    enemy = whatEnemy(*bunny, *weakling, *wolf, *goofball,
                                      *bear, *strangler, *madman, *rhino,
                                      *craber, *predator, *apex, *rip);
                    intf.initializeEnemy(enemy);
                    intf.fighting(*tracker, *player, world, *potion, inventory);
                    getch();
                }

            } else {

                // player does nothing

            }
        } else if (input == 's' || input == 'S') { // move down

            check = world.playerMoveDown();
            tracker->increaseSteps();
            if (check && world.getPlayerY() < 44) {

                std::random_device r;

                std::default_random_engine el(r());
                std::uniform_real_distribution<float> chance_dist(0, 1);

                chestOrEnemy = chance_dist(el);
                if (chestOrEnemy < 0.3) {

                    system("cls");
                    std::cout << "Congratulations, a Lost Chest has been found.\n";
                    foundChest = whatChest(weapons, common, uncommon, rare, urare);
                    LostLoot *updatedChest = inventory.addToInventoryChest(foundChest);
                    if (updatedChest != nullptr) {
                        updatedChest->increaseQuantity(); // Update the quantity of the returned chest object
                    }

                    getch();

                } else {

                    tracker->increaseEncounters();
                    system("cls");
                    std::cout << "Enemy enountered!!!\n";
                    enemy = whatEnemy(*bunny, *weakling, *wolf, *goofball,
                                      *bear, *strangler, *madman, *rhino,
                                      *craber, *predator, *apex, *rip);
                    intf.initializeEnemy(enemy);
                    intf.fighting(*tracker, *player, world, *potion, inventory);
                    getch();
                }

            } else {

                // player does nothing

            }
        } else if (input == 'd' || input == 'D') { // move right

            check = world.playerMoveRight();
            tracker->increaseSteps();
            if (check && world.getPlayerX() < 199) {

                std::random_device r;

                std::default_random_engine el(r());
                std::uniform_real_distribution<float> chance_dist(0, 1);

                chestOrEnemy = chance_dist(el);
                if (chestOrEnemy < 0.5) {

                    system("cls");
                    std::cout << "Congratulations, a Lost Chest has been found.\n";
                    foundChest = whatChest(weapons, common, uncommon, rare, urare);
                    LostLoot *updatedChest = inventory.addToInventoryChest(foundChest);
                    if (updatedChest != nullptr) {
                        updatedChest->increaseQuantity(); // Update the quantity of the returned chest object
                    }

                    getch();

                } else {

                    tracker->increaseEncounters();
                    system("cls");
                    std::cout << "Enemy enountered!!!\n";
                    enemy = whatEnemy(*bunny, *weakling, *wolf, *goofball,
                                      *bear, *strangler, *madman, *rhino,
                                      *craber, *predator, *apex, *rip);
                    intf.initializeEnemy(enemy);
                    intf.fighting(*tracker, *player, world, *potion, inventory);
                    getch();
                }

            } else {

                // player does nothing

            }
        } else if (input == 'b' || input == 'B') { // open inventory

            system("cls");
            inventory.showAll();
            std::cout << std::endl;
            intf.showInventoryBottom();

            inventoryOpen = true;

            while (inventoryOpen) {

                std::cout << std::endl;
                std::cin >> input;

                if (input == '1') {

                    system("cls");
                    prevInput = input;
                    inventory.showAll();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                } else if (input == '2') {

                    system("cls");
                    prevInput = input;
                    inventory.showHats();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                    std::cout << " [E] - Equip an item from the list\n";
                } else if (input == '3') {

                    system("cls");
                    prevInput = input;
                    inventory.showChestplates();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                    std::cout << " [E] - Equip an item from the list\n";
                } else if (input == '4') {

                    system("cls");
                    prevInput = input;
                    inventory.showLeggings();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                    std::cout << " [E] - Equip an item from the list\n";
                } else if (input == '5') {

                    system("cls");
                    prevInput = input;
                    inventory.showBoots();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                    std::cout << " [E] - Equip an item from the list\n";
                } else if (input == '6') {

                    system("cls");
                    prevInput = input;
                    inventory.showWeapons();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                    std::cout << " [E] - Equip an item from the list\n";
                } else if (input == '7') {

                    system("cls");
                    prevInput = input;
                    inventory.showPotions();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                    std::cout << " [E] - Use a potion\n";
                } else if (input == '8') {

                    system("cls");
                    prevInput = input;
                    inventory.showChests();
                    std::cout << std::endl;
                    intf.showInventoryBottom();
                    std::cout << " [E] - Open a chest\n";

                } else if (input == 'e' || input == 'E') {

                    // 2 - hat; 3 - chesplt; 4 -leggings; 5 - boots; 6 - weapons; 7 - potion; 8 - chests
                    if (prevInput == '2') { // equip hat

                        std::cout << "Select an item to equip:\n";
                        std::cin >> equipChoice;

                        Hat* hat = inventory.getHat(equipChoice);
                        player->removeHat();
                        player->setHat(hat);
                        system("cls");
                        inventory.showAll();
                        std::cout << std::endl;
                        intf.showInventoryBottom();
                    } else if (prevInput == '3') { // equip chestplate

                        std::cout << "Select an item to equip:\n";
                        std::cin >> equipChoice;

                        Chestplate chestplate = inventory.getChestplate(equipChoice);
                        player->removeChestplate();
                        player->setChestplate(chestplate);
                        system("cls");
                        inventory.showAll();
                        std::cout << std::endl;
                        intf.showInventoryBottom();
                    } else if (prevInput == '4') { // equip leggings

                        std::cout << "Select an item to equip:\n";
                        std::cin >> equipChoice;

                        Leggings leggings = inventory.getLeggings(equipChoice);
                        player->removeLeggings();
                        player->setLeggings(leggings);
                        system("cls");
                        inventory.showAll();
                        std::cout << std::endl;
                        intf.showInventoryBottom();
                    } else if (prevInput == '5') { // equip boots

                        std::cout << "Select an item to equip:\n";
                        std::cin >> equipChoice;

                        Boots boots = inventory.getBoots(equipChoice);
                        player->removeBoots();
                        player->setBoots(boots);
                        system("cls");
                        inventory.showAll();
                        std::cout << std::endl;
                        intf.showInventoryBottom();
                    } else if (prevInput == '6') { // equip a weapon

                        std::cout << "Select an item to equip:\n";
                        std::cin >> equipChoice;

                        Weapon weapon = inventory.getWeapon(equipChoice);
                        player->removeWeapons();
                        player->setWeapon(weapon);
                        system("cls");
                        inventory.showAll();
                        std::cout << std::endl;
                        intf.showInventoryBottom();
                    } else if (prevInput == '7') { // use potion

                        player->usePotion(*potion, inventory);
                        getch();
                        system("cls");
                        inventory.showAll();
                        std::cout << std::endl;
                        intf.showInventoryBottom();

                    } else if (prevInput == '8') { // open chest

                        std::cout << "Select a chest to open:\n";
                        std::cin >> equipChoice;
                        bool safeCheck;

                        safeCheck = inventory.checkIfEmpty();

                        if (!safeCheck) {
                            foundChest = inventory.getChest(equipChoice);
                            inventory.addToInventoryItem(foundChest.dropItem());
                            inventory.removeFromInventoryChest(foundChest);
                        }   else {

                            std::cout << "\nYou do not have any chests.\n";
                            getch();
                        }
                        system("cls");
                        inventory.showAll();
                        std::cout << std::endl;
                        intf.showInventoryBottom();
                    } else if(prevInput == 'e' || prevInput == 'E'){

                        std::cout << "You have to select an inventory category first.\n";
                    } else {

                        std::cout << "No such option\n";
                    }

                } else if (input == 'b' || input == 'B') {

                    inventoryOpen = false;
                } else std::cout << "No such option.\n";
            }
        } else if (input == 'p' || input == 'P') { // shop

            system("cls");
            intf.showShopBottom();
            std::cout << std::endl;
            std::cout << "\nGold owned: " << player->getCurreny() << std::endl;
            shopOpen = true;

            while(shopOpen){

                std::cout << std::endl;
                std::cin >> input;

                if (input == '1'){

                    system("cls");
                    shop.listHats();
                    std::cout << std::endl;
                    intf.showShopBottom();
                    std::cout << "[B] - Buy an item from the section\n";
                    std::cout << std::endl;
                    std::cout << "Gold owned: " << player->getCurreny() << std::endl;
                }   else if (input == '2'){

                    system("cls");
                    shop.listChestplates();
                    std::cout << std::endl;
                    intf.showShopBottom();
                    std::cout << "[B] - Buy an item from the section\n";
                    std::cout << std::endl;
                    std::cout << "Gold owned: " << player->getCurreny() << std::endl;
                }   else if (input == '3'){

                    system("cls");
                    shop.listLeggings();
                    std::cout << std::endl;
                    intf.showShopBottom();
                    std::cout << "[B] - Buy an item from the section\n";
                    std::cout << std::endl;
                    std::cout << "Gold owned: " << player->getCurreny() << std::endl;
                }   else if (input == '4'){

                    system("cls");
                    shop.listBoots();
                    std::cout << std::endl;
                    intf.showShopBottom();
                    std::cout << "[B] - Buy an item from the section\n";
                    std::cout << std::endl;
                    std::cout << "Gold owned: " << player->getCurreny() << std::endl;
                }   else if (input == '5'){

                    system("cls");
                    shop.listWeapons();
                    std::cout << std::endl;
                    intf.showShopBottom();
                    std::cout << "[B] - Buy an item from the section\n";
                    std::cout << std::endl;
                    std::cout << "Gold owned: " << player->getCurreny() << std::endl;
                }   else if (input == '6'){

                    system("cls");
                    shop.listPotion();
                    std::cout << std::endl;
                    intf.showShopBottom();
                    std::cout << "[B] - Buy an item from the section\n";
                    std::cout << std::endl;
                    std::cout << "Gold owned: " << player->getCurreny() << std::endl;
                }   else if (input == 'b' && !isblank(prevInput) || input == 'B' && !isblank(prevInput)){

                            std::cout << "\nWhich item are you looking to buy?\n";
                            std::cout << std::endl;
                            std::cin >> itemNum;
                            std::cout << "How much of the item are you looking to buy?\n";
                            std::cout << std::endl;
                            std::cin >> quantity;
                            std::cout << std::endl;

                            if (prevInput == '1'){ // hat section

                                userBuying = shop.buyItem(hatsShop.at(itemNum-1), quantity, *player, *tracker);
                                if (userBuying) {

                                    for (int i = 0; i < quantity; i++) {
                                        inventory.addToInventoryItem(hatsShop.at(itemNum - 1));
                                    }   std::cout << "Items have been added to your inventory.\n";
                                }   else std::cout << "Sorry, it seems you don't have enough money.\n";
                                getch();
                                system("cls");
                                intf.showShopBottom();
                                std::cout << std::endl;
                                std::cout << "\nGold owned: " << player->getCurreny() << std::endl;

                            }   else if (prevInput == '2'){ // chestlpate section

                                userBuying = shop.buyItem(chestplatesShop.at(itemNum-1), quantity, *player, *tracker);
                                if (userBuying) {

                                    for (int i = 0; i < quantity; i++) {
                                        inventory.addToInventoryItem(chestplatesShop.at(itemNum - 1));
                                    }   std::cout << "Items have been added to your inventory.\n";
                                }   else std::cout << "Sorry, it seems you don't have enough money.\n";
                                getch();
                                system("cls");
                                intf.showShopBottom();
                                std::cout << std::endl;
                                std::cout << "\nGold owned: " << player->getCurreny() << std::endl;
                            }   else if (prevInput == '3'){ // leggings section

                                userBuying = shop.buyItem(leggingsShop.at(itemNum-1), quantity, *player, *tracker);
                                if (userBuying) {

                                    for (int i = 0; i < quantity; i++) {
                                        inventory.addToInventoryItem(leggingsShop.at(itemNum - 1));
                                    }   std::cout << "Items have been added to your inventory.\n";
                                }   else std::cout << "Sorry, it seems you don't have enough money.\n";
                                getch();
                                system("cls");
                                intf.showShopBottom();
                                std::cout << std::endl;
                                std::cout << "\nGold owned: " << player->getCurreny() << std::endl;
                            }   else if (prevInput == '4'){ // boots section

                                userBuying = shop.buyItem(bootsShop.at(itemNum-1), quantity, *player, *tracker);
                                if (userBuying) {

                                    for (int i = 0; i < quantity; i++) {
                                        inventory.addToInventoryItem(bootsShop.at(itemNum - 1));
                                    }   std::cout << "Items have been added to your inventory.\n";
                                }   else std::cout << "Sorry, it seems you don't have enough money.\n";
                                getch();
                                system("cls");
                                intf.showShopBottom();
                                std::cout << std::endl;
                                std::cout << "\nGold owned: " << player->getCurreny() << std::endl;
                            }   else if (prevInput == '5'){ // weapons section

                                userBuying = shop.buyItem(weaponShop.at(itemNum-1), quantity, *player, *tracker);
                                if (userBuying) {

                                    for (int i = 0; i < quantity; i++) {
                                        inventory.addToInventoryItem(weaponShop.at(itemNum - 1));
                                    }   std::cout << "Items have been added to your inventory.\n";
                                }   else std::cout << "Sorry, it seems you don't have enough money.\n";
                                getch();
                                system("cls");
                                intf.showShopBottom();
                                std::cout << std::endl;
                                std::cout << "\nGold owned: " << player->getCurreny() << std::endl;
                            }   else if (prevInput == '6'){ // potion section

                                userBuying = shop.buyItem(potion, quantity, *player, *tracker);
                                if (userBuying) {

                                    for (int i = 0; i < quantity; i++) {
                                        inventory.addToInventoryItem(potion);
                                    }   std::cout << "Items have been added to your inventory.\n";
                                }   else std::cout << "Sorry, it seems you don't have enough money.\n";
                                getch();
                                system("cls");
                                intf.showShopBottom();
                                std::cout << std::endl;
                                std::cout << "\nGold owned: " << player->getCurreny() << std::endl;
                            }   else std::cout << "\nNo such option\n";



                }   else if (input == 'p' || input == 'P'){
                    shopOpen = false;
                }   else std::cout << "No such option.\n";

                prevInput = input;

            }

        } else if (input == 'o' || input == 'O') {

            system("cls");
            intf.showStats(*tracker, *player, achievements);
            getch();
        } else if (input == 'c' || input == 'C') {

            characterOpen = true;

            while (characterOpen) {

                system("cls");
                intf.showCharacter(*player);

                if (player->getAP() > 0) {

                    std::cout << std::endl;
                    intf.showAbilityBottomAP();
                    std::cout << std::endl;
                    std::cin >> input;
                    if (input == '1') {

                        player->increaseDamage();
                        std::cout << std::endl;
                        std::cout << "Damage increased.\n";
                        getch();
                        system("cls");
                        intf.showCharacter(*player);
                        intf.showAbilityBottomAP();

                    } else if (input == '2') {

                        player->increaseDefense();
                        std::cout << std::endl;
                        std::cout << "Defense increased.\n";
                        getch();
                        system("cls");
                        intf.showCharacter(*player);
                        intf.showAbilityBottomAP();
                    } else if (input == '3') {

                        player->increaseHealth();
                        std::cout << std::endl;
                        std::cout << "Health increased.\n";
                        getch();
                        system("cls");
                        intf.showCharacter(*player);
                        intf.showAbilityBottomAP();
                    } else if (input == 'c' || input == 'C') {

                        characterOpen = false;
                    } else {

                        std::cout << std::endl;
                        std::cout << "No such option.\n";
                        getch();
                        system("cls");
                    }

                } else {

                    system("cls");

                    intf.showCharacter(*player);
                    std::cout << std::endl;
                    intf.showAbilityBottomNoAP();
                    std::cout << std::endl;
                    std::cin >> input;

                    if (input == 'c' || input == 'C') {

                        characterOpen = false;
                    } else {

                        std::cout << std::endl;
                        std::cout << "No such option.\n";
                        getch();
                    }
                }

            }
        } else if (input == '>') {

            return 0;
        }

    }

}