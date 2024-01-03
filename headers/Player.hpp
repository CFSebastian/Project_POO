//
// Created by sebas on 04.12.2023.
//
#include <SFML/Graphics.hpp>
#include <vector>

#ifndef OOP_PLAYER_HPP
#define OOP_PLAYER_HPP

#include "Entity.hpp"
#include "Bullet.hpp"

class Player : public Entity {
    ///Player
    int hpMax;
    ///Bullets
    int counter;
    //std::vector<Bullet<sf::Mouse>> Bullets;
    //BUllet<sf::Mouse> b;
    Bullet b;
    std::vector<Bullet> bullets;
    sf::Vector2<float> aimDir, aimDirNorm;

public:
    Player()=default;


    Player(int hp, float speed, sf::CircleShape &shape,
           const sf::Vector2<float> &center, const sf::Color &eColor,const Bullet &bullet);
    //Player(const sf::CircleShape &shape, const sf::Color &color, const int &hp, const int &speed, int hpMax, float size);

    void eMove() override;

    int getHpMax() const;

    //void shooting(const sf::RenderWindow &window);
    //void eDraw(sf::RenderWindow &window) override;
    ~Player() override=default;

};


#endif //OOP_PLAYER_HPP
