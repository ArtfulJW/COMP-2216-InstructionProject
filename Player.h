#pragma once
#include "Math.h"
#include "vector"
#include "Bullet.h"

class Player {

public:

    // Constructor
    Player(float x, float y);

    // Getter
    float getX();
    float getY();
    float getRad();
    bool getAttacking();

    // Setter
    void setAlive(bool input);

    // Functions
    void movePlayer();
    bool checkAlive();
    void drawPlayer();

    void calcSwordPointer();
    void drawSwordPointer();

    // Attack
    void shoot(std::vector <Bullet> &);

private:
    bool alive;
    float x;
    float y;
    float swordPointerX;
    float swordPointerY;
    float radius;
    int speed;
    bool attacking;

};