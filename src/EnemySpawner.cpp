//
// Created by sebas on 02.01.2024.
//

#include "../headers/EnemySpawner.hpp"
//#include <SFML/Graphics.hpp>
#include <math.h>

Enemy EnemySpawner::zombi() {
    return Enemy(100,0.5f,sf::CircleShape(10.f,4),sf::Vector2f (500.f,500.f),sf::Color::Green,25);
}

Enemy EnemySpawner::golem() {
    return Enemy(100,0.25f,sf::CircleShape(20.f,8),sf::Vector2f (500.f,500.f),sf::Color::Blue,50);
}

Enemy EnemySpawner::smallZombi() {
    return Enemy(100,0.75f,sf::CircleShape(5.f,4),sf::Vector2f (500.f,500.f),sf::Color::Cyan,12);
}

template<class T>
Enemy EnemySpawner::generateEnamy(T enemyType) {
    enemyType=enemyType%10;
    if(0<=enemyType&&enemyType<=4)
        return zombi();
    if(5<=enemyType&&enemyType<=7)
        return golem();
    if(8<=enemyType&&enemyType<=9)
        return smallZombi();
    return zombi();
}

template<>
Enemy EnemySpawner::generateEnamy(int enemyType) {
    enemyType=enemyType%10;
    if(0<=enemyType&&enemyType<=4)
        return zombi();
    if(5<=enemyType&&enemyType<=7)
        return golem();
    if(8<=enemyType&&enemyType<=9)
        return smallZombi();
    return zombi();
}
template<>
Enemy EnemySpawner::generateEnamy(float enemyType) {
    double integral;
    int fractional = (int)modf(enemyType, &integral)%10;
    if(0<=fractional && fractional<=4)
        return zombi();
    if(5<=fractional && fractional<=7)
        return golem();
    if(8<=fractional && fractional<=9)
        return smallZombi();
    return zombi();
}