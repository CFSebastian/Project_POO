//
// Created by sebas on 04.12.2023.
//

#include "../headers/Player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
/*Player::Player(const sf::CircleShape &shape, const sf::Color &color, const int &hp, const int &speed, int hpMax,float size)
        : Entity( hp, speed, shape, center, eColor), hpMax(hpMax) {
}*/
Player::Player(int hp, float speed, sf::CircleShape &shape,
               const sf::Vector2<float> &center, const sf::Color &eColor,const Bullet &bullet) : Entity(hp, speed, shape, center, eColor), hpMax(hp), b(bullet) {
    //this->shape.setPosition(center);
    this->counter=bullet.getFireRate();
}

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
/*void Player::shooting(const sf::RenderWindow &window) {
    ///Player shooting
    sf::Vector2<float> mousePos;
    sf::Vector2<float> playerPos;
    mousePos=sf::Vector2f(sf::Mouse::getPosition(window));
    //std::cout<<mousePos.x<<" "<<mousePos.y<<"\n";
    playerPos=sf::Vector2f(this->shape.getPosition().x+this->shape.getRadius(),
                               this->shape.getPosition().y+this->shape.getRadius());
    this->aimDir=mousePos-playerPos;;
    this->aimDirNorm=this->aimDir/(float)sqrt(pow(this->aimDir.x,2) + pow(this->aimDir.y,2));

    //this->counter=b.getFireRate();
    int fireRate=b.getFireRate();
    if(counter<fireRate)
        counter++;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && counter>=fireRate)
    {

        b.setVelocity(aimDirNorm);
        b.setCenter(shape.getPosition());
        this->bullets.push_back(b);
        counter=0;
    }
    for (auto &bullet : bullets) {
        bullet.eMove();
    }
    for(size_t i=0;i<bullets.size();i++) {
        //std::cout<<i<<" movet to :"<<b.getCenter().x<<" "<<b.getCenter().y<<"\n";
        this->bullets[i].eMove();
        //std::cout<<i<<" movet to :"<<bullets[i].getCenter().x<<" "<<bullets[i].getCenter().y<<"\n";
    }

}
void Player::eDraw(sf::RenderWindow &window) {
    window.draw(shape);
    for (auto &bullet : bullets) {
        bullet.eDraw(window);
    }
    for(size_t i=0;i<bullets.size();i++)
    {
        std::cout<<i<<" movet to :"<<bullets[i].getCenter().x<<" "<<bullets[i].getCenter().y<<"\n";
        bullets[i].eDraw(window);
    }
}*/

