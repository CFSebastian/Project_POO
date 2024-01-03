/*
 * Nume fisier:Player.phh
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */
#include <SFML/Graphics.hpp>

#ifndef OOP_PLAYER_HPP
#define OOP_PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity {
    ///Player
    int hpMax;
    ///Bullets
public:
    Player()=default;


    Player(int hp, float speed, sf::CircleShape &shape,
           const sf::Vector2<float> &center, const sf::Color &eColor);

    void eMove() override;

    int getHpMax() const;

    ~Player() override=default;

};


#endif //OOP_PLAYER_HPP
