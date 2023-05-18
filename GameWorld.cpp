//
// Created by CyEm on 5/8/2023.
//

#include "GameWorld.h"
#include <iostream>
#include <windows.h>
#include <random>

GameWorld::GameWorld() {}

void GameWorld::setUpInitial(int y, int x) {

    HEIGHT = y; // rows
    LENGTH = x; // columns

    row = vector<char>(LENGTH, '.');
    worldMap = vector<vector<char>>(HEIGHT, row);

}

int positionXGenerator(int LENGTH) {

    std::random_device r;

    std::default_random_engine el(r());
    std::uniform_int_distribution<int> chance_dist(0, LENGTH - 1);

    int X = chance_dist(el);

    return X;

}

int positionYGenerator(int HEIGHT) {

    std::random_device r;

    std::default_random_engine el(r());
    std::uniform_int_distribution<int> chance_dist(0, HEIGHT - 1);

    int Y = chance_dist(el);

    return Y;

}

void GameWorld::setUpLostPos(int choiceD) { // ratio to difficulty size

    int ratioList[4] = {16, 14, 12, 10};
    int lostAmount = (HEIGHT * LENGTH) / ratioList[choiceD - 1];

    for (int i = 0; i < lostAmount; i++) {

        worldMap[positionYGenerator(HEIGHT - 1)][positionXGenerator(LENGTH - 1)] = '!';
    }

}

void GameWorld::setPlayerLoc() {

    playerY = positionYGenerator(HEIGHT);
    playerX = positionXGenerator(LENGTH);

    worldMap[playerY][playerX] = '@';
}

void GameWorld::playerFled() {

    worldMap[playerY][playerX] = '!';
    setPlayerLoc();
}

bool GameWorld::playerMoveUp() {

    if (playerY > 0) {

        worldMap[playerY][playerX] = '.';
        playerY--;
        if (worldMap[playerY][playerX] == '!') {

            worldMap[playerY][playerX] = '@';
            return true;
        } else {

            worldMap[playerY][playerX] = '@';
            return false;
        }
    }
}

bool GameWorld::playerMoveLeft() {

    if (playerX > 0) {

        worldMap[playerY][playerX] = '.';
        playerX--;
        if (worldMap[playerY][playerX] == '!') {

            worldMap[playerY][playerX] = '@';
            return true;
        } else {

            worldMap[playerY][playerX] = '@';
            return false;
        }
    }
}

bool GameWorld::playerMoveRight() {

    if (playerX < LENGTH - 1) {

        worldMap[playerY][playerX] = '.';
        playerX++;
        if (worldMap[playerY][playerX] == '!') {

            worldMap[playerY][playerX] = '@';
            return true;
        } else {

            worldMap[playerY][playerX] = '@';
            return false;
        }
    }
}

bool GameWorld::playerMoveDown() {

    if (playerY < HEIGHT - 1) {

        worldMap[playerY][playerX] = '.';
        playerY++;
        if (worldMap[playerY][playerX] == '!') {

            worldMap[playerY][playerX] = '@';
            return true;

        }   else {

            worldMap[playerY][playerX] = '@';
            return false;
        }

    }
}

int GameWorld::getPlayerX() {
    return playerX;
}

int GameWorld::getPlayerY() {
    return playerY;
}

void GameWorld::printMap() {

    HANDLE col;
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < worldMap.size(); i++) {

        for (int j = 0; j < worldMap[i].size(); j++) {

            if (worldMap[i][j] == '.') {

                SetConsoleTextAttribute(col, 2);
                std::cout << worldMap[i][j];

            } else if (worldMap[i][j] == '!') {

                SetConsoleTextAttribute(col, 12);
                std::cout << worldMap[i][j];
            } else if (worldMap[i][j] == '@') {

                SetConsoleTextAttribute(col, 14);
                std::cout << worldMap[i][j];
            } else {

                std::cout << worldMap[i][j];
            }
        }
        std::cout << std::endl;
    }


}
