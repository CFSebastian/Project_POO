/*
 * Nume fisier:EnemySpawner.cpp
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere: factory design pattern
 */

#include "../headers/EnemySpawner.hpp"

#include <math.h>

Enemy EnemySpawner::zombi(Builder &builder) {
    builder.buildDamage(25);
    builder.buildHP(100);
    builder.buildShape(sf::CircleShape(10.f,4),sf::Vector2f (500.f,500.f),sf::Color::Green);
    builder.buildSpeed(0.5f);
    return builder.getResult();
}

Enemy EnemySpawner::golem(Builder &builder) {
    builder.buildDamage(50);
    builder.buildHP(100);
    builder.buildShape(sf::CircleShape(20.f,8),sf::Vector2f (500.f,500.f),sf::Color::Blue);
    builder.buildSpeed(0.25f);
    return builder.getResult();
}

Enemy EnemySpawner::smallZombi(Builder &builder) {
    builder.buildDamage(12);
    builder.buildHP(100);
    builder.buildShape(sf::CircleShape(5.f,4),sf::Vector2f (500.f,500.f),sf::Color::Cyan);
    builder.buildSpeed(0.75f);
    return builder.getResult();
}

template<class T>
Enemy EnemySpawner::generateEnamy(T enemyType) {
    EnemyBuilder builder1;
    enemyType=enemyType%10;
    if(0<=enemyType&&enemyType<=4)
        return zombi(builder1);
    if(5<=enemyType&&enemyType<=7)
        return golem(builder1);
    if(8<=enemyType&&enemyType<=9)
        return smallZombi(builder1);
    return zombi(builder1);
}

template<>
Enemy EnemySpawner::generateEnamy(int enemyType) {
    EnemyBuilder builder1;
    enemyType=enemyType%10;
    if(0<=enemyType&&enemyType<=4)
        return zombi(builder1);
    if(5<=enemyType&&enemyType<=7)
        return golem(builder1);
    if(8<=enemyType&&enemyType<=9)
        return smallZombi(builder1);
    return zombi(builder1);
}
template<>
Enemy EnemySpawner::generateEnamy(float enemyType) {
    EnemyBuilder builder1;
    double integral;
    int fractional = (int)modf(enemyType, &integral)%10;
    if(0<=fractional && fractional<=4)
        return zombi(builder1);
    if(5<=fractional && fractional<=7)
        return golem(builder1);
    if(8<=fractional && fractional<=9)
        return smallZombi(builder1);
    return zombi(builder1);
}