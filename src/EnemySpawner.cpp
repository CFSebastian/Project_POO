/*
 * Nume fisier:EnemySpawner.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere: factory design pattern, a fost schimbat joi/1/2024 sa foloseasca builder-ul in loc de constractor-ul clasei 
 */

#include "../headers/EnemySpawner.hpp"

#include <math.h>

Enemy EnemySpawner::zombi(EnemyBuilder &builder) {
    builder.buildDamage(25);
    builder.buildHP(100);
    builder.buildShape(sf::CircleShape(10.f,4),sf::Vector2f (500.f,500.f),sf::Color::Green);
    builder.buildSpeed(0.5f);
    return builder.getResult();
}

Enemy EnemySpawner::golem(EnemyBuilder &builder) {
    builder.buildDamage(50);
    builder.buildHP(100);
    builder.buildShape(sf::CircleShape(20.f,8),sf::Vector2f (500.f,500.f),sf::Color::Blue);
    builder.buildSpeed(0.25f);
    return builder.getResult();
}

Enemy EnemySpawner::smallZombi(EnemyBuilder &builder) {
    builder.buildDamage(12);
    builder.buildHP(100);
    builder.buildShape(sf::CircleShape(5.f,4),sf::Vector2f (500.f,500.f),sf::Color::Cyan);
    builder.buildSpeed(0.75f);
    return builder.getResult();
}

template<class T>
Enemy EnemySpawner::generateEnamy(T enemyType) {
    EnemyBuilder builderZ, builderG, builderSz;
    enemyType=enemyType%10;
    if(0<=enemyType&&enemyType<=4)
        return zombi(builderZ);
    if(5<=enemyType&&enemyType<=7)
        return golem(builderG);
    if(8<=enemyType&&enemyType<=9)
        return smallZombi(builderSz);
    return zombi(builderZ);
}

template<>
Enemy EnemySpawner::generateEnamy(int enemyType) {
    EnemyBuilder builderZ, builderG, builderSz;
    enemyType=enemyType%10;
    if(0<=enemyType&&enemyType<=4)
        return zombi(builderZ);
    if(5<=enemyType&&enemyType<=7)
        return golem(builderG);
    if(8<=enemyType&&enemyType<=9)
        return smallZombi(builderSz);
    return zombi(builderZ);
}
template<>
Enemy EnemySpawner::generateEnamy(float enemyType) {
    EnemyBuilder builderZ, builderG, builderSz;
    double integral;
    int fractional = (int)modf(enemyType, &integral)%10;
    if(0<=fractional && fractional<=4)
        return zombi(builderZ);
    if(5<=fractional && fractional<=7)
        return golem(builderG);
    if(8<=fractional && fractional<=9)
        return smallZombi(builderSz);
    return zombi(builderZ);
}