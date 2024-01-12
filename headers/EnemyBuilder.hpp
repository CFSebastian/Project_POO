/*
 * Nume fisier:EnemySpawner.phh
 * Autor: Colt Sebastian
 * Data: 11/01/2024
 * Descriere: builder design pattern
 */

#ifndef OOP_ENEMYBUILDER_HPP
#define OOP_ENEMYBUILDER_HPP
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class EnemyBuilder{
    Enemy enemy;
public:
     EnemyBuilder()=default;
     void buildShape(const sf::CircleShape &shape, const sf::Vector2f &poz, const sf::Color &color);
     void buildHP (const int &HP);
     void buildSpeed (const float &speed );
     void buildDamage (const int &damage);
     Enemy getResult();
};


#endif //OOP_ENEMYBUILDER_HPP
