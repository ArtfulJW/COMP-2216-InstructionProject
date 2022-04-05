#include "raylib.h"
#include "Bullet.h"

Bullet::Bullet(float x, float y) {
	this->x = x;
	this->y = y;
	this->radius = 4;
	this->gotDest = false;
	this->reachDest = false;
}

void Bullet::update(){
}

bool Bullet::getReachDest() {
	return this->reachDest;
}

void Bullet::getMouseCoord() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && this->gotDest == false) {
		this->dest_x = GetMouseX();
		this->dest_y = GetMouseY();
		this->gotDest = true;
	}
}

void Bullet::calcBullet() {

	this->getMouseCoord();

	float dx = this->dest_x - this->x;
	float dy = this->dest_y - this->y;

	float angle = atan2f(dy, dx);

	this->x +=  cosf(angle) * 2;
	this->y +=  sinf(angle) * 2;

}

void Bullet::drawBullet() { 
	Vector2 destVector{ this->dest_x, this->dest_y };
	Vector2 currentVector{ this->x, this->y };

	if (!(CheckCollisionCircles(destVector, 2, currentVector, this->radius))) {
		DrawCircle(this->x, this->y, this->radius, GREEN);
	}
	else {
		this->reachDest = true;
	}

}
