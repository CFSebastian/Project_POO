/*
 * Nume fisier:Entiry.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */

#include "../headers/Entity.hpp"
Entity::Entity(int hp, float speed, sf::CircleShape shape, const sf::Vector2<float> &center, const sf::Color &eColor)
        : HP(hp), speed(speed), shape(shape) {
    this->shape.setPosition(center);
    this->shape.setFillColor(eColor);
}
Entity& Entity::operator=(const Entity &entity)
{
    this->HP=entity.HP;
    this->speed=entity.speed;
    this->shape=entity.shape;
    return *this;
}
Entity::Entity(const Entity &entity) {
    this->HP=entity.HP;
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
    return HP;
}

bool Entity::collison(Entity &e1, Entity &e2) {
    if(e1.shape.getGlobalBounds().intersects(e2.shape.getGlobalBounds()))
        return true;
    return false;
}

void Entity::setHp(int hp) {
    HP = hp;
}


