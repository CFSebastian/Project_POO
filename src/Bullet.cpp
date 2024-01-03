/*
 * Nume fisier:Bullet.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */

#include "../headers/Bullet.hpp"

#include <math.h>

Bullet::Bullet( int hp, float speed, const sf::CircleShape &shape, const sf::Vector2<float> &center, const sf::Color &eColor,
                int damage, const int &fireRate) : Entity(hp, speed, shape, center, eColor), damage(damage),fireRate(fireRate),
                                                   velocity(0.f,0.f) {}

Bullet::Bullet(const Bullet &bullet) : Entity(bullet), damage(bullet.damage), fireRate(bullet.fireRate), velocity(bullet.velocity) {}

Bullet& Bullet::operator=(const Bullet &bullet)
{
    this->HP=bullet.HP;
    this->speed=bullet.speed;
    this->shape=bullet.shape;
    this->damage=bullet.damage;
    this->fireRate=bullet.fireRate;
    this->velocity=bullet.velocity;
    return *this;
}
void Bullet::eMove() {
    this->shape.move(velocity);
}

int Bullet::getFireRate() const {
    return fireRate;
}

void Bullet::setVelocity(const sf::Vector2<float> &aimDirNorm) {
    Bullet::velocity = aimDirNorm*speed;
}
