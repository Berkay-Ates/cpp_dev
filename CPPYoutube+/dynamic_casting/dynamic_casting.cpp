#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

class Entity {};
class Player : public Entity {};
class Enemy : public Entity {};

int main() {
    Player* player = new Player();
    Entity* actuallyEnemy = new Enemy();

    Entity* actuallyPlayer = player;

    if (dynamic_cast<Player*>(actuallyEnemy)) {
    }

    Player* p0 = dynamic_cast<Player*>(actuallyEnemy);
    Player* p1 = dynamic_cast<Player*>(actuallyPlayer);
}