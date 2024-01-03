#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
//#include <chrono>
#include <thread>
#include <math.h>
#include <vector>
#include <cstdlib>
///My headers
#include "headers/Game.hpp"

///LENGHT OF VECTOR: |V|=sqrt(V.x^2+V.y^2)
///NORMALIZE VECTOR: U+V/|V|

#ifdef __linux__
#include <X11/Xlib.h>
#endif

using namespace sf;

/*class Bullet
{
public:
    CircleShape shape;
    Vector2<float> velocity;
    float speed;
    Bullet(float radius=5.f)
        : velocity(0.f,0.f),speed(25.f) {
        this->shape.setRadius(radius);
        this->shape.setFillColor(Color::White);
    }
};*/
int main() {
/*
    srand(time(nullptr));
    sf::RenderWindow window;
    /// NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:30
    window.create(sf::VideoMode({800, 800}), "My Game Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);
    ///PLayewr
    CircleShape player(25.f);
    player.setFillColor(Color::White);
    ///Bullet
    int n=20;
    Bullet b;
    std::vector<Bullet> bullets;
    ///Enemy
    RectangleShape enemy;
    enemy.setFillColor(Color::Magenta);
    enemy.setSize(Vector2f(50.f,50.f));
    int counter=20;
    std::vector<RectangleShape> enemys;

    ///Vector
    Vector2<float> playerCenter;
    sf::Vector2<float> mousePos;
    Vector2<float> aimDir, aimDirNorm;

    //sf::Vector2f center(100.f,100.f);
    //sf::CircleShape shape(20.f,5);
    //Player p(100,5,shape,center,sf::Color::Red);
    while(window.isOpen()) {
        sf::Event e;
        while(window.pollEvent(e)) {
            ///Options for interacting with the window
            switch(e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << "New width: " << window.getSize().x << '\n'
                              << "New height: " << window.getSize().y << '\n';
                    break;
                case sf::Event::KeyPressed:
                    if(e.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                //case sf::Event::KeyPressed:
                     //   std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                     //   break;
                default:
                    break;
            }

        }

        ///Update
        //vector
        mousePos=sf::Vector2f(sf::Mouse::getPosition(window));
        playerCenter=Vector2f (player.getPosition().x+player.getRadius(),
                               player.getPosition().y+player.getRadius());
        aimDir=mousePos-playerCenter;
        aimDirNorm=aimDir/(float )sqrt(pow(aimDir.x,2)+pow(aimDir.y,2));
        std::cout<<aimDirNorm.x<<" "<<aimDirNorm.y<<"\n";
        //player
        if(Keyboard::isKeyPressed(Keyboard::A))
            player.move(-10.f,0.f);
        if(Keyboard::isKeyPressed(Keyboard::D))
            player.move(10.f,0.f);
        if(Keyboard::isKeyPressed(Keyboard::W))
            player.move(0.f,-10.f);
        if(Keyboard::isKeyPressed(Keyboard::S))
            player.move(0.f,10.f);
        /// enemy
        if(counter<20)
            counter++;
        if(counter>=20 && enemys.size()<50) {
            enemy.setPosition(Vector2f(rand()%window.getSize().x,rand()%window.getSize().y));
            enemys.push_back(RectangleShape(enemy));

            counter=0;
        }

        /// shoot
        if(n<20)
            n++;
        if(Mouse::isButtonPressed(Mouse::Left)&&n>=20) {
            b.shape.setPosition(playerCenter);
            b.velocity=aimDirNorm*b.speed;
            bullets.push_back(Bullet(b));
            n=0;
        }
        for(size_t i=0;i<bullets.size();i++){
            bullets[i].shape.move(bullets[i].velocity);
            if(bullets[i].shape.getPosition().y<0||bullets[i].shape.getPosition().x<0||
                    bullets[i].shape.getPosition().y>window.getSize().y||bullets[i].shape.getPosition().x>window.getSize().x)
            {
                bullets.erase(bullets.begin()+i);
            }
            else {
                //enemy collison
                for(size_t j=0;j<enemys.size();j++)
                {
                    if(bullets[i].shape.getGlobalBounds().intersects(enemys[j].getGlobalBounds()))
                    {
                        bullets.erase(bullets.begin()+i);
                        enemys.erase(enemys.begin()+j);
                        break;
                    }
                }
            }

        }
        ///Draw
        window.clear();
        ///Draw evrething
        for(size_t i=0;i<enemys.size();i++)
        {
            window.draw(enemys[i]);
        }
        window.draw(player);
        for(size_t i=0;i<bullets.size();i++) {
            window.draw(bullets[i].shape);
        }
        window.display();
    }

*/
    ///Start code
    Game& Game=Game::getInstance();
    Game.runGame();

    return 0;
}
