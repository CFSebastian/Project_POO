/*
 * Nume fisier:Entiry.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */

#include "../headers/Entity.hpp"

Entity::Entity(const int &hp, const float &speed, sf::CircleShape shape, const sf::Vector2<float> &center, const sf::Color &eColor)
        : hp(hp), speed(speed), shape(std::move(shape)) {
    this->shape.setPosition(center);
    this->shape.setFillColor(eColor);
}

Entity& Entity::operator = (const Entity &entity)
{
    this->hp=entity.hp;
    this->speed=entity.speed;
    this->shape=entity.shape;
    return *this;
}
Entity::Entity(const Entity &entity) {
    this->hp=entity.hp;
    this->speed=entity.speed;
    this->shape=entity.shape;
}

void Entity::eDraw(sf::RenderWindow &window) {
    window.draw(shape);

}

const sf::Vector2<float> &Entity::getCenter() const {
    return shape.getPosition();
}

void Entity::setCenter(const sf::Vector2<float> &center) {
    //Entity::center = center;
    this->shape.setPosition(center);
}

int Entity::getHp() const {
    return hp;
}

bool Entity::collison(Entity &e1, Entity &e2) {
    if(e1.shape.getGlobalBounds().intersects(e2.shape.getGlobalBounds()))
        return true;
    return false;
}

void Entity::setHp(int hp) {
    this->hp = hp;
}

void Entity::setShape(const sf::CircleShape &shape, const sf::Vector2f &poz, const sf::Color &color) {
    Entity::shape = shape;
    Entity::shape.setPosition(poz);
    Entity::shape.setFillColor(color);
}

void Entity::setSpeed(float speed) {
    Entity::speed = speed;
}

Entity::Entity(int hp, float speed, const sf::CircleShape &shape) : hp(hp), speed(speed), shape(shape) {}


