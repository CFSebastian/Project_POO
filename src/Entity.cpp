//
// Created by sebas on 04.12.2023.
//
//#include "iostream"
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
    //this->center=entity.center;
    //this->eColor=entity.eColor;
}

void Entity::eDraw(sf::RenderWindow &window) {
    window.draw(shape);
    //std::cout<<"after movet to :"<<shape.getPosition().x<<" "<<shape.getPosition().y<<"\n";
}

/*float Entity::getSpeed() const {
    return speed;
}*/


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


