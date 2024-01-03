/*
 * Nume fisier:Player.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */

#include "../headers/Player.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>

Player::Player(int hp, float speed, sf::CircleShape &shape,
               const sf::Vector2<float> &center, const sf::Color &eColor) : Entity(hp, speed, shape, center, eColor), hpMax(hp) {}

void Player::eMove() {
    ///PLayer walking movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.move(-speed,0.f);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.move(speed,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape.move(0.f,-speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape.move(0.f,speed);
    }

}

int Player::getHpMax() const {
    return hpMax;
}


