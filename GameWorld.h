//
// Created by CyEm on 5/8/2023.
//
#include <string>
#include <vector>
#ifndef INFINITY_GAMEWORLD_H
#define INFINITY_GAMEWORLD_H

using std::vector;


class GameWorld {
private:

    int playerX, playerY;
    vector<char> row;
    vector<vector<char>> worldMap;
    int HEIGHT, LENGTH;

public:

    GameWorld();

    int getPlayerY();
    int getPlayerX();
    void setUpInitial(int, int);
    void setUpLostPos(int);
    void setPlayerLoc();
    void printMap();
    void playerFled();
    bool playerMoveUp();
    bool playerMoveLeft();
    bool playerMoveRight();
    bool playerMoveDown();


};


#endif //INFINITY_GAMEWORLD_H
