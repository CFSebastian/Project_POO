/*
 * Nume fisier:Bullet.phh
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */
#include <SFML/Graphics.hpp>
#ifndef OOP_BULLET_HPP
#define OOP_BULLET_HPP
#include "Entity.hpp"

class Bullet : public Entity{
    int damage;
    int fireRate;
    sf::Vector2<float> velocity;

public:
    Bullet()=default;
    ~Bullet() override=default;
    Bullet(int hp, float speed, const sf::CircleShape &shape, const sf::Vector2<float> &center, const sf::Color &eColor,
           int damage, const int &fireRate);

    Bullet(const Bullet &bullet);
    Bullet& operator=(const Bullet &bullet) ;
    void eMove() override;

    int getFireRate() const;

    void setVelocity(const sf::Vector2<float> &velocity);
};


#endif //OOP_BULLET_HPP
