//
// Created by sebas on 04.12.2023.
//
#include <SFML/Graphics.hpp>
#ifndef OOP_ENEMY_HPP
#define OOP_ENEMY_HPP
#include "Entity.hpp"

class Enemy : public Entity {
private:
    int damage;
    sf::Vector2<float> velocity;
public:
    Enemy()=default;
    ~Enemy() override=default;

    Enemy(int hp, float speed, const sf::CircleShape &shape, const sf::Vector2<float> &center, const sf::Color &eColor,
          int damage);

    Enemy(const Enemy &enemy);

    void eMove() override;

    int getDamage() const;

    void setVelocity(const sf::Vector2<float> &velocity);

};


#endif //OOP_ENEMY_HPP
