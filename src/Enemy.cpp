/*
 * Nume fisier:Enemy.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */

#include "../headers/Enemy.hpp"

Enemy::Enemy(int hp, float speed, const sf::CircleShape &shape, const sf::Vector2<float> &center,
             const sf::Color &eColor, int damage) : Entity(hp, speed, shape, center, eColor), damage(damage), velocity(0.f,0.f) {}

Enemy::Enemy(const Enemy &enemy) : Entity(enemy), damage(enemy.damage), velocity(enemy.velocity) {}

void Enemy::eMove() {
    this->shape.move(velocity);
}

void Enemy::setVelocity(const sf::Vector2<float> &dirNorm) {
    Enemy::velocity = speed*dirNorm;
}

int Enemy::getDamage() const {
    return damage;
}

void Enemy::setDamage(const int &damage) {
    this->damage = damage;
}

Enemy::Enemy(int hp, float speed, const sf::CircleShape &shape, int damage) : Entity(hp, speed, shape),
                                                                              damage(damage) {}

void Enemy::setShape(const sf::CircleShape &shape, const sf::Vector2f &poz, const sf::Color &color) {
    Entity::shape = shape;
    Entity::shape.setPosition(poz);
    Entity::shape.setFillColor(color);
    this->velocity=sf::Vector2f (0.f,0.f);
}