#include "raylib.h"
#include "Player.h"
#include "vector"
#include "Bullet.h"

// Constructor
Player::Player(float x, float y) {
    this->alive = true;
    this->x = x;
    this->y = y;
    this->swordPointerX = 0;
    this->swordPointerY = 0;
    this->radius = 6; 
    this->speed = 4;
    this->attacking = false;
}

float Player::getX() {
    return this->x;
}

float Player::getY() {
    return this->y;
}

float Player::getRad() {
    return this->radius;
}

bool Player::getAttacking() {
    return this->attacking;
}

void Player::setAlive(bool input) {
    this->alive = input;
}

bool Player::checkAlive() {

    return this->alive;
}

void Player::movePlayer() {

    if (IsKeyDown(KEY_D)) {
        this->x += speed;
    }
    if (IsKeyDown(KEY_A)) {
        this->x -= speed;
    }
    if (IsKeyDown(KEY_W)) {
        this->y -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        this->y += speed;
    }

}

void Player::drawPlayer() {
    if (this->checkAlive()) {
        DrawCircle(this->getX(), this->getY(), this->getRad(), BLACK);
    }
}

void Player::calcSwordPointer() {

    // Get Distances
    float dx = GetMouseX() - this->x;
    float dy = GetMouseY() - this->y;

    // Calculate Angle - "Point" at Cursor
    float angle = atan2f(dy, dx);

    this->swordPointerX = this->x + cosf(angle) * 25;
    this->swordPointerY = this->y + sinf(angle) * 25;

}

void Player::drawSwordPointer(){

    calcSwordPointer();
    DrawCircle(this->swordPointerX, this->swordPointerY,4,BLACK);

}

void Player::shoot(std::vector<Bullet> &bulletList) {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && bulletList.size() < 30) {
        /*DrawCircle(this->swordPointerX, this->swordPointerY,5,GREEN);*/
        Bullet newBullet(this->swordPointerX,this->swordPointerY);

        bulletList.push_back(newBullet);

        newBullet.calcBullet();
        newBullet.drawBullet();
        
    }

}
