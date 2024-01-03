//
// Created by sebas on 04.12.2023.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
//#include <chrono>
#include <thread>
#include <math.h>
#include <cstdlib>
///my headers
#include "../headers/Player.hpp"
#include "../headers/EnemySpawner.hpp"
#include "../headers/GameUI.hpp"
#ifdef __linux__
#include <X11/Xlib.h>
#endif

#include "../headers/Game.hpp"

Game* Game::instance = nullptr;
void Game::runGame() {
    srand(time(nullptr));
    sf::RenderWindow window;
    /// NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:30
    window.create(sf::VideoMode({800, 800}), "My Game Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);
    sf::Vector2f mousePos;
    /*
    //window.setFramerateLimit(120);
    sf::CircleShape shape(20.f,5);
    shape.setPosition(sf::Vector2(0.f,0.f));
    sf::Color color;
    color=sf::Color::Red;
    shape.setFillColor(color);


    sf::RectangleShape rect(sf::Vector2(50.f,100.f));
    rect.setPosition(sf::Vector2(400.f,200.f));

    sf::Vertex line[]={sf::Vertex(sf::Vector2f (100.f,400.f)),
                       sf::Vertex(sf::Vector2(50.f,100.f))};
    sf::ConvexShape con;
    //resize it to 5 points
    con.setPointCount(5);
    con.setPosition(sf::Vector2(200.f,400.f));
    //defin the points
    con.setPoint(0,sf::Vector2f (0,0));
    con.setPoint(1,sf::Vector2f (150,10));
    con.setPoint(2,sf::Vector2f (120,90));
    con.setPoint(3,sf::Vector2f (30,100));
    con.setPoint(4,sf::Vector2f (0,50));
*/
    sf::Vector2f center(100.f,100.f);
    sf::CircleShape shape(20.f,5);
    ///Bullets
    int playerFire=25;
    sf::Vector2f aimDir, aimDirNorm;
    Bullet gun1(1,15,sf::CircleShape(10.f),sf::Vector2f (0.f,0.f),sf::Color::Yellow,50,25);

    ///PLayer
    Player p(100,5,shape,center,sf::Color::White,gun1);
    sf::Vector2f playerPos;
    GameUI<int> ui(p.getHp(),p.getHpMax());
    ///Enemys
    int enemyCounter=5;
    Enemy zombi(100,0.5f,sf::CircleShape(10.f,8),sf::Vector2f (500.f,500.f),sf::Color::Green,25);
    sf::Vector2f directionDir, directionDirNorm;
    sf::Vector2f enemyPos;

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
                /*case sf::Event::KeyPressed:
                    std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                    break;*/
                default:
                    break;
            }

        }

        ///Update
        ///Input
        mousePos=sf::Vector2f(sf::Mouse::getPosition(window));

        ///PLayer
        p.eMove();
        //p.shooting(window);
        playerPos=p.getCenter();

        ///Enemys
        //directionDir=mousePos-playerPos;
        //directionDirNorm=directionDir/(float)sqrt(pow(directionDir.x,2) + pow(directionDir.y,2));
        //zombi.setVelocity(directionDirNorm);
        if(enemyCounter<40)
            enemyCounter++;
        if(enemyCounter>=40 && enemys.size()<50) {
            //zombi.setCenter(sf::Vector2f(rand()%window.getSize().x,rand()%window.getSize().y));
            enemys.push_back(std::make_shared<Enemy>(EnemySpawner::generateEnamy<int>(rand())));
            enemys.back()->setCenter(sf::Vector2f(rand()%window.getSize().x,rand()%window.getSize().y));
            enemyCounter=0;
        }
        for(auto &enemy : enemys) {
            enemyPos=enemy->getCenter();
            directionDir=playerPos-enemyPos;
            directionDirNorm=directionDir/(float)sqrt(pow(directionDir.x,2) + pow(directionDir.y,2));
            enemy->setVelocity(directionDirNorm);
            enemy->eMove();
        }

        ///PlayerShoot
        aimDir=mousePos-playerPos;
        aimDirNorm=aimDir/(float)sqrt(pow(aimDir.x,2) + pow(aimDir.y,2));
        if(playerFire<gun1.getFireRate())
            playerFire++;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && playerFire>=gun1.getFireRate())
        {
            gun1.setVelocity(aimDirNorm);
            gun1.setCenter(p.getCenter());
            playerBullets.push_back(Bullet(gun1));
            playerFire=0;
        }
        for(size_t i=0;i<playerBullets.size();i++) {
            playerBullets[i].eMove();
            if(playerBullets[i].getCenter().y<-10||playerBullets[i].getCenter().x<-10||
                    playerBullets[i].getCenter().y>window.getSize().y+10||playerBullets[i].getCenter().x>window.getSize().x+10)
            {
                playerBullets.erase(playerBullets.begin()+i);
            }
            else {
                //enemy collison
                for(size_t j=0;j<enemys.size();j++)
                {
                    if(Entity::collison(playerBullets[i],*enemys[j]))
                    {
                        playerBullets.erase(playerBullets.begin()+i);
                        enemys.erase(enemys.begin()+j);
                        break;
                    }

                }
            }
        }
        ///Player intersects enemys
        for(size_t j=0;j<enemys.size();j++)
            if(Entity::collison(p,*enemys[j]))
            {
                p.setHp(p.getHp()-enemys[j]->getDamage());
                //std::cout<<p.getHp();
                enemys.erase(enemys.begin()+j);
                break;
            }
        ui.update(p.getHp());
        if(p.getHp()<0)
            window.close();
        /*for(auto &enemy : enemys){
            enemy->eMove();
        }*/
        //mousePos=sf::Vector2f(sf::Mouse::getPosition(window));
        //shape.move(0.6f,0.3f);
        //shape.rotate(5.f);
        ///Draw
        // window.clear(sf::Color::Red);
        window.clear();
        ///Draw evrething
        ///Player draw
        p.eDraw(window);
        ///Enemy Draw
        for(auto &enemy : enemys){
            enemy->eDraw(window);
        }
        ///Bullets draw
        for (auto &bullet : playerBullets) {
            bullet.eDraw(window);
        }
        ui.uDraw(window);
        //window.draw(shape);
        //window.draw(rect);
        //window.display();
        //window.draw(line,2,sf::Lines);
        //window.draw(con);
        //using namespace std::chrono_literals;
        //std::this_thread::sleep_for(300ms);
        window.display();

    }

}