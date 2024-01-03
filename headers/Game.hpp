/*
 * Nume fisier:Game.phh
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere: singleton design pattern
 */

#ifndef OOP_GAME_HPP
#define OOP_GAME_HPP
#include <vector>
#include <memory>

#include "Enemy.hpp"
#include "Bullet.hpp"

class Game {
    std::vector<std::shared_ptr<Enemy>> enemys;
    std::vector<Bullet> playerBullets;
    static Game* instance;
    Game()=default;
    ~Game()=default;
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    static Game& getInstance() {
        if(!instance) {
            instance = new Game();
        }
        return *instance;
    }
    void runGame();

};


#endif //OOP_GAME_HPP
