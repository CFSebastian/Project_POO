//
// Created by sebas on 03.01.2024.
//
#include <SFML/Graphics.hpp>
#ifndef OOP_GAMEUI_HPP
#define OOP_GAMEUI_HPP


template <class T>
class GameUI {
    T hp,maxHp;
    sf::RectangleShape bar, barBack;
private:
public:
    GameUI(const T &hp,const T &maxHp) : hp(hp), maxHp(maxHp) {
    bar.setPosition(5.f,5.f);
    bar.setSize(sf::Vector2f (150.f,5.f));
    bar.setFillColor(sf::Color::Red);
    barBack.setPosition(0.f,0.f);
    barBack.setSize(sf::Vector2f (160.f,15.f));
    barBack.setFillColor(sf::Color::White);

}
    void update(const T &playerHp) {
    this->hp=playerHp;
    float hpPercent=static_cast<float>(hp)/maxHp;
    this->bar.setSize(sf::Vector2f (150.f*hpPercent,5.f));

}
    void uDraw(sf::RenderWindow &window){
        window.draw(barBack);
        window.draw(bar);
}

};


#endif //OOP_GAMEUI_HPP
