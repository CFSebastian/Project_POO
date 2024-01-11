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
#include "EnemyBuilder.hpp"

class EnemySpawner {

public:
    template <class T>
    static Enemy generateEnamy(T enemyType);
    static Enemy zombi(Builder &builder);
    static Enemy golem(Builder &builder);
    static Enemy smallZombi(Builder &builder);

};


#endif //OOP_ENEMYSPAWNER_HPP
