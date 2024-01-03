/*
 * Nume fisier:main.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */

///My headers
#include "headers/Game.hpp"

int main() {

    ///Start game
    Game& Game=Game::getInstance();
    Game.runGame();

    return 0;
}
