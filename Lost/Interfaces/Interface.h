//
// Created by CyEm on 5/12/2023.
//

#ifndef INFINITY_INTERFACE_H
#define INFINITY_INTERFACE_H


#include "../Looting/LostEnemy.h"
#include "../Player.h"
#include "../../GameWorld.h"
#include "../Shop/Shop.h"
#include "../ServicesManager.h"
#include "../Scoring/Achievements.h"

class Interface {
private:

    /* fight vars */
    LostEnemy enemy;

public:

    Interface();

    /* MAIN */
    void initializeEnemy(LostEnemy enemy);
    void showBottomWhileMap(Player&);

    /* SHOP */
    void showShopBottom();

    /* INVENTORY */

    void showInventoryBottom();
    void showStats(ServicesManager&, Player&, Achievements&);

    /* FIGHT */

    void fighting(ServicesManager&, Player&, GameWorld&, Potion&, Inventory&);

    /* USER ABILITIES */

    void showCharacter(Player&);
    void showAbilityBottomAP();
    void showAbilityBottomNoAP();

};


#endif //INFINITY_INTERFACE_H
