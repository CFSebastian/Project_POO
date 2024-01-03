//
// Created by sebas on 04.12.2023.
//
#include <SFML/Graphics.hpp>
#ifndef OOP_BULLET_HPP
#define OOP_BULLET_HPP
#include "Entity.hpp"

class Bullet : public Entity{
    int damage;
    int fireRate;
    sf::Vector2<float> velocity;
    //sf::CircleShape shape;

public:
    Bullet()=default;
    ~Bullet() override=default;
    Bullet(int hp, float speed, const sf::CircleShape &shape, const sf::Vector2<float> &center, const sf::Color &eColor,
           int damage, const int &fireRate);

    Bullet(const Bullet &bullet);

    void eMove() override;

    int getFireRate() const;

    //const sf::Vector2<float> &getVelocity() const;

    //void shoot(sf::Vector2<float> eCenter);

    void setVelocity(const sf::Vector2<float> &velocity);
};


#endif //OOP_BULLET_HPP
