//
// Created by sebas on 11.01.2024.
//

#include "../headers/EnemyBuilder.hpp"
EnemyBuilder::EnemyBuilder() {
    enemy=Enemy();
}
 void EnemyBuilder::buildShape(const sf::CircleShape &shape, const sf::Vector2f &poz, const sf::Color &color)  {
    enemy.setShape(shape,poz,color);

}
 void EnemyBuilder::buildHP (const int &HP) {
    enemy.setHp(HP);
}
 void EnemyBuilder::buildSpeed (const float &speed ) {
    enemy.setSpeed(speed);
}
 void EnemyBuilder::buildDamage (const int &damage) {
    enemy.setDamage(damage);
}
Enemy EnemyBuilder::getResult() {
    return enemy;
}