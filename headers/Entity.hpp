/*
 * Nume fisier:Entity.phh
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere:
 */

#ifndef OOP_ENTITY_HPP
#define OOP_ENTITY_HPP
#include <SFML/Graphics.hpp>

class Entity {
protected:
    int hp;
    float speed;
    sf::CircleShape shape;
public:
    Entity()=default;

    virtual ~Entity() = default;

    Entity(const int &hp,const  float &speed, sf::CircleShape shape, const sf::Vector2<float> &center, const sf::Color &eColor);

    Entity(int hp, float speed, const sf::CircleShape &shape);

    Entity(const Entity &entity);

    Entity& operator=(const Entity &entity) ;

    const sf::Vector2<float> &getCenter() const;

    virtual void eMove()=0;

    virtual void eDraw(sf::RenderWindow &window);


    int getHp() const;

    static bool collison(Entity &e1, Entity &e2);

    void setCenter(const sf::Vector2<float> &center);

    void setHp(int hp);

    void setShape(const sf::CircleShape &shape, const sf::Vector2f &poz, const sf::Color &color);

    void setSpeed(float speed);


};

#endif //OOP_ENTITY_HPP
