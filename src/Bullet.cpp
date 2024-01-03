//
// Created by sebas on 04.12.2023.
//

#include "../headers/Bullet.hpp"

#include <math.h>
#include <iostream>
Bullet::Bullet( int hp, float speed, const sf::CircleShape &shape, const sf::Vector2<float> &center, const sf::Color &eColor,
                int damage, const int &fireRate) : Entity(hp, speed, shape, center, eColor), damage(damage),fireRate(fireRate),
               velocity(0.f,0.f) {}
Bullet::Bullet(const Bullet &bullet) : Entity(bullet), damage(bullet.damage), fireRate(bullet.fireRate), velocity(bullet.velocity) {}

void Bullet::eMove() {
    this->shape.move(velocity);
}

/*void Bullet::eMove() {
    //std::cout<<" "<<this->velocity.x<<" "<<this->velocity.y<<"\n";
    //shape.move(this->velocity);
    //std::cout<<"before movet to :"<<shape.getPosition().x<<" "<<shape.getPosition().y<<"\n";
    shape.move(velocity);
    //std::cout<<"after movet to :"<<shape.getPosition().x<<" "<<shape.getPosition().y<<"\n";
}*/

int Bullet::getFireRate() const {
    return fireRate;
}

void Bullet::setVelocity(const sf::Vector2<float> &aimDirNorm) {
    Bullet::velocity = aimDirNorm*speed;
}

const sf::Vector2<float> &Bullet::getVelocity() const {
    return velocity;
}
/*
void Bullet::shoot(sf::Vector2<float> eCenter) {

    this->center=eCenter;
    this->shape.setPosition(this->center);
    this->velocity = this->aimDirNorm*this->speed;
    std::cout<<eCenter.x<<" "<<eCenter.y<<" - "<<this->center.x<<" "<<this->center.y<<" "<<this->velocity.y<<" "<<this->velocity.x<<"\n";
}
*/