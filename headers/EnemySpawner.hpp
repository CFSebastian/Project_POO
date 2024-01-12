/*
 * Nume fisier:EnemySpawner.phh
 * Autor: Colt Sebastian
 * Data: 03/01/2024
 * Descriere: factory design pattern, a fost schimbat joi/1/2024 sa foloseasca builder-ul in loc de constractor-ul clasei
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
    static Enemy zombi(EnemyBuilder &builder);
    static Enemy golem(EnemyBuilder &builder);
    static Enemy smallZombi(EnemyBuilder &builder);

};


#endif //OOP_ENEMYSPAWNER_HPP
