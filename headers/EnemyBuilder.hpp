//
// Created by sebas on 11.01.2024.
//

#ifndef OOP_ENEMYBUILDER_HPP
#define OOP_ENEMYBUILDER_HPP
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>
class Builder {
public:
    virtual void buildShape(const sf::CircleShape &shape, const sf::Vector2f &poz, const sf::Color &color)=0;
    virtual void buildHP (const int &HP)=0;
    virtual void buildSpeed (const float &speed )=0;
    virtual void buildDamage (const int &damage)=0;
    virtual Enemy getResult()=0;
};
class EnemyBuilder: public Builder{
    Enemy enemy;
public:
     EnemyBuilder()=default;
     void buildShape(const sf::CircleShape &shape, const sf::Vector2f &poz, const sf::Color &color) override;
     void buildHP (const int &HP) override;
     void buildSpeed (const float &speed ) override;
     void buildDamage (const int &damage) override;
     Enemy getResult() override;
};


#endif //OOP_ENEMYBUILDER_HPP
