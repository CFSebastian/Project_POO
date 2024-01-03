/*
 * Nume fisier:EnemySpawner.phh
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere: factory design pattern
 */

#ifndef OOP_ENEMYSPAWNER_HPP
#define OOP_ENEMYSPAWNER_HPP
#include <cstdlib>
#include "Enemy.hpp"
class EnemySpawner {

public:
    template <class T>
    static Enemy generateEnamy(T enemyType);
    static Enemy zombi();
    static Enemy golem();
    static Enemy smallZombi();

};


#endif //OOP_ENEMYSPAWNER_HPP
