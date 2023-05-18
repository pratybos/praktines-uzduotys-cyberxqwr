//
// Created by CyEm on 5/10/2023.
//

#include <iostream>
#include <conio.h>
#include "Inventory.h"
#include "Potion/Potion.h"

Inventory::Inventory() {}

Item *Inventory::addToInventoryItem(Item *item_) {

    if (item_->getQuantity() == 0) {

        std::cout << item_->getName() << " has been added to your inventory!\n";
        getch();
        all.push_back(item_);
        item_->increaseQuantity();

        switch (item_->getID()) {
            case 1: {
                Hat *hat = dynamic_cast<Hat *>(item_);
                getch();
                for (auto &existingHat: hats) {
                    if (hat->getName() == existingHat->getName()) {
                        existingHat->increaseQuantity();
                        delete hat; // Delete the duplicate hat
                        return existingHat;
                    }
                }
                hats.push_back(hat);
                return hats.back();
            }
            case 2: {
                Chestplate *chestplate = reinterpret_cast<Chestplate *>(item_);
                for (auto &existingChestplate: chestplates) {
                    if (chestplate->getName() == existingChestplate->getName()) {
                        existingChestplate->increaseQuantity();
                        delete chestplate; // Delete the duplicate chestplate
                        return existingChestplate;
                    }
                }
                chestplates.push_back(chestplate);
                return chestplates.back();
            }
            case 3: {
                Leggings *leggingsItem = reinterpret_cast<Leggings *>(item_);
                for (auto &existingLeggings: leggings) {
                    if (leggingsItem->getName() == existingLeggings->getName()) {
                        existingLeggings->increaseQuantity();
                        delete leggingsItem; // Delete the duplicate leggings
                        return existingLeggings;
                    }
                }
                leggings.push_back(leggingsItem);
                return leggings.back();
            }
            case 4: {
                Boots *bootsItem = reinterpret_cast<Boots *>(item_);
                for (auto &existingBoots: boots) {
                    if (bootsItem->getName() == existingBoots->getName()) {
                        existingBoots->increaseQuantity();
                        delete bootsItem; // Delete the duplicate boots
                        return existingBoots;
                    }
                }
                boots.push_back(bootsItem);
                return boots.back();
            }
            case 5: {
                Potion *potion = reinterpret_cast<Potion *>(item_);
                for (auto &existingPotion: potions) {
                    if (potion->getName() == existingPotion->getName()) {
                        existingPotion->increaseQuantity();
                        delete potion; // Delete the duplicate potion
                        return existingPotion;
                    }
                }
                potions.push_back(potion);
                return potions.back();
            }
            case 6: {
                Weapon *weapon = reinterpret_cast<Weapon *>(item_);
                for (auto &existingWeapon: weapons) {
                    if (weapon->getName() == existingWeapon->getName()) {
                        existingWeapon->increaseQuantity();
                        delete weapon; // Delete the duplicate weapon
                        return existingWeapon;
                    }
                }
                weapons.push_back(weapon);
                return weapons.back();
            }
        }
    } else {
        item_->increaseQuantity();
    }

    return nullptr;
}

void Inventory::removeFromInventoryChest(LostLoot &chest_) {
    for (auto it = chests.begin(); it != chests.end(); ++it) {
        if (*it == chest_) {
            (*it).decreaseQuantity();
            if ((*it).getQuantity() == 0) {
                chests.erase(it);
            }
            break;
        }
    }
}

void Inventory::potionUsed(Potion &potion_) {

    potion_.decreaseQuantity();
}


LostLoot *Inventory::addToInventoryChest(LostLoot &chest_) {
    bool chestExists = false;
    for (auto &chest: chests) {
        if (chest.getName() == chest_.getName()) {
            chest.increaseQuantity();
            chestExists = true;
            break;
        }
    }

    if (!chestExists) {
        chests.push_back(chest_);
        chest_.increaseQuantity();
        return &chests.back(); // Return a pointer to the newly added chest
    }

    return nullptr; // Return nullptr if the chest already exists
}

LostLoot* Inventory::getLostLoot(int choice) {
    if (!chests.empty() && choice >= 1 && choice <= chests.size()) {
        return &chests.at(choice - 1);
    } else {
        std::cout << "Invalid choice or no chests in the inventory.\n";
        return nullptr;
    }
}

void Inventory::showAll() {

    std::cout << "-------------------- Inventory - All Items ------------------------\n";
    std::cout << std::endl;

    if (!all.empty()) {
        vector<Item *>::iterator it;
        int itemPlacement = 1;


        for (it = all.begin(); it != all.end(); ++it) {
            if ((*it)->getName() != "Health potion") {
                std::cout << itemPlacement << ". Name: " << (*it)->getName() << " Item's damage: " << (*it)->getDamage()
                          <<
                          " Item's defense: " << (*it)->getDefense() << " Item's max health increase: "
                          << (*it)->getHealth()
                          << " Item's quantity: " <<
                          (*it)->getQuantity() << std::endl;
            } else {

                std::cout << itemPlacement << ". Name: " << potions.at(0)->getName() << " Item's healing: "
                          << potions.at(0)->getHealth() <<
                          " Item's quantity: " << potions.at(0)->getQuantity() << std::endl;
            }

            itemPlacement += 1;
        }
    } else std::cout << "Inventory is empty\n";
}

void Inventory::showHats() {

    std::cout << "-------------------- Inventory - Hats ------------------------\n";
    std::cout << std::endl;

    if (!hats.empty()) {
        vector<Item *>::iterator it;
        int itemPlacement = 1;


        for (it = hats.begin(); it != hats.end(); ++it) {
            std::cout << itemPlacement << ". Name: " << (*it)->getName() << " Item's damage: " << (*it)->getDamage() <<
                      " Item's defense: " << (*it)->getDefense() << " Item's max health increase: "
                      << (*it)->getHealth()
                      << " Item's quantity: " <<
                      (*it)->getQuantity() << std::endl;;

            itemPlacement += 1;
        }
    } else std::cout << "No hats available\n";
}

Hat *Inventory::getHat(int choice) {
    if (!hats.empty() && choice >= 1 && choice <= hats.size()) {
        Item *selectedItem = hats.at(choice - 1); // Get a pointer to the selected item
        std::cout << "Equipped " << selectedItem->getName() << std::endl;
        getch();
        Hat *hat = dynamic_cast<Hat *>(selectedItem); // Perform a downcast to Hat*
        if (hat) {
            return hat;
        } else {
            std::cout << "Invalid choice. The selected item is not a Hat.\n";
        }
    } else {
        std::cout << "Invalid choice or no hats in the inventory.\n";
    }
    return nullptr; // Return a null pointer if the choice is invalid or no hats in inventory
}

Chestplate Inventory::getChestplate(int choice) {

    if (!chestplates.empty() && choice >= 1 && choice <= chestplates.size()) {
        Item &selectedItem = *chestplates.at(choice - 1);
        std::cout << "Equipped " << selectedItem.getName() << std::endl;
        getch();
        return dynamic_cast<Chestplate &>(selectedItem);
    } else {
        std::cout << "Invalid choice or no chestplates in the inventory.\n";
    }
    return Chestplate();
}

Leggings Inventory::getLeggings(int choice) {

    if (!leggings.empty() && choice >= 1 && choice <= leggings.size()) {
        Item &selectedItem = *leggings.at(choice - 1);
        std::cout << "Equipped " << selectedItem.getName() << std::endl;
        getch();
        return dynamic_cast<Leggings &>(selectedItem);
    } else {
        std::cout << "Invalid choice or no leggings in the inventory.\n";
    }
    return Leggings();
}

Boots Inventory::getBoots(int choice) {

    if (!boots.empty() && choice >= 1 && choice <= boots.size()) {
        Item &selectedItem = *boots.at(choice - 1);
        std::cout << "Equipped " << selectedItem.getName() << std::endl;
        getch();
        return dynamic_cast<Boots &>(selectedItem);
    } else {
        std::cout << "Invalid choice or no boots in the inventory.\n";
    }
    return Boots();
}

Weapon Inventory::getWeapon(int choice) {

    if (!weapons.empty() && choice >= 1 && choice <= weapons.size()) {
        Item &selectedItem = *weapons.at(choice - 1);
        std::cout << "Equipped " << selectedItem.getName() << std::endl;
        getch();
        return dynamic_cast<Weapon &>(selectedItem);
    } else {
        std::cout << "Invalid choice or no weapons in the inventory.\n";
    }
    return Weapon();
}

LostLoot Inventory::getChest(int choice) {

        if (choice <= chests.size() && choice > 0) {

            return chests.at(choice - 1);
        } else {

            std::cout << "No such item.\n";
            std::cin >> choice;
            return getChest(choice);
        }

}

bool Inventory::checkIfEmpty() {

    if (chests.empty()) return true;

    return false;
}

void Inventory::showChestplates() {

    std::cout << "-------------------- Inventory - Chestplates ------------------------\n";
    std::cout << std::endl;

    if (!chestplates.empty()) {
        vector<Item *>::iterator it;
        int itemPlacement = 1;


        for (it = chestplates.begin(); it != chestplates.end(); ++it) {
            std::cout << itemPlacement << ". Name: " << (*it)->getName() << " Item's damage: " << (*it)->getDamage() <<
                      " Item's defense: " << (*it)->getDefense() << " Item's max health increase: "
                      << (*it)->getHealth()
                      << " Item's quantity: " <<
                      (*it)->getQuantity() << std::endl;

            itemPlacement += 1;
        }
    } else std::cout << "No chestplates available\n";
}

void Inventory::showLeggings() {

    std::cout << "-------------------- Inventory - Leggings ------------------------\n";
    std::cout << std::endl;

    if (!leggings.empty()) {
        vector<Item *>::iterator it;
        int itemPlacement = 1;

        for (it = leggings.begin(); it != leggings.end(); ++it) {
            std::cout << itemPlacement << ". Name: " << (*it)->getName() << " Item's damage: " << (*it)->getDamage() <<
                      " Item's defense: " << (*it)->getDefense() << " Item's max health increase: "
                      << (*it)->getHealth()
                      << " Item's quantity: " <<
                      (*it)->getQuantity() << std::endl;

            itemPlacement += 1;
        }
    } else std::cout << "No leggings available\n";
}

void Inventory::showBoots() {

    std::cout << "-------------------- Inventory - Boots ------------------------\n";
    std::cout << std::endl;

    if (!boots.empty()) {
        vector<Item *>::iterator it;
        int itemPlacement = 1;

        for (it = boots.begin(); it != boots.end(); ++it) {
            std::cout << itemPlacement << ". Name: " << (*it)->getName() << " Item's damage: " << (*it)->getDamage() <<
                      " Item's defense: " << (*it)->getDefense() << " Item's max health increase: "
                      << (*it)->getHealth()
                      << " Item's quantity: " <<
                      (*it)->getQuantity() << std::endl;;

            itemPlacement += 1;
        }
    } else std::cout << "No boots available\n";
}

void Inventory::showPotions() {

    std::cout << "-------------------- Inventory - Potions ------------------------\n";
    std::cout << std::endl;

    if (!potions.empty()) {

        std::cout << "1. Name: " << potions.at(0)->getName() << " Item's healing: " << potions.at(0)->getHealth() <<
                  " Item's quantity: " << potions.at(0)->getQuantity() << std::endl;
    } else std::cout << "No potions available\n";
}

void Inventory::showWeapons() {

    std::cout << "-------------------- Inventory - Weapons ------------------------\n";
    std::cout << std::endl;

    if (!weapons.empty()) {
        vector<Item *>::iterator it;
        int itemPlacement = 1;

        for (it = weapons.begin(); it != weapons.end(); ++it) {
            std::cout << itemPlacement << ". Name: " << (*it)->getName() << " Item's damage: " << (*it)->getDamage() <<
                      " Item's defense: " << (*it)->getDefense() << " Item's max health increase: "
                      << (*it)->getHealth()
                      << " Item's quantity: " <<
                      (*it)->getQuantity() << std::endl;

            itemPlacement += 1;
        }
    } else std::cout << "No weapons available\n";
}

void Inventory::showChests() {

    std::cout << "-------------------- Inventory - Chests ------------------------\n";
    std::cout << std::endl;

    if (!chests.empty()) {
        vector<LostLoot>::iterator it;
        int itemPlacement = 1;

        for (it = chests.begin(); it != chests.end(); ++it) {
            std::cout << itemPlacement << ". Name: " << it->getName() << ". Quantity: " << it->getQuantity()
                      << std::endl;

            itemPlacement += 1;
        }
    } else std::cout << "No chests available\n";
}
