//
// Created by CyEm on 5/9/2023.
//

#ifndef INFINITY_ITEM_H
#define INFINITY_ITEM_H
#include <string>

using std::string;


class Item {
protected:

    string name;
    int damage;
    int defense;
    int health;
    int price;
    int quantity;
    int id;

public:

    virtual ~Item() = default;

    Item(string, int, int, int, int, int, int);
    Item();
    Item(string, int);

    int getDamage();
    int getDefense();
    int getHealth();
    int getPrice();
    int getQuantity();
    string getName();
    int getID();
    void increaseQuantity();
    void decreaseQuantity();
};


#endif //INFINITY_ITEM_H
