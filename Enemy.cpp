#include "raylib.h"
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy(float x, float y) {
	this->x = x;
	this->y = y;
	this->width = 10;
	this->height = 10;
	this->alive = true;
}

bool Enemy::getAlive(){
	return this->alive;
}

void Enemy::setAlive(bool alive) {
	this->alive = alive;
}

void Enemy::moveEnemy(Player player) {

	float newX = player.getX() - this->x;
	float newY = player.getY() - this->y;

	float length = sqrtf(newX * newX + newY * newY);

	if (length > 0) {
		this->x += (newX * 1.5) / length;
		this->y += (newY * 1.5) / length;
	}

	
}

void Enemy::checkCollidePlayer(Player &player) {

	Rectangle rectangle{ (float)this->x, (float)this->y, (float)this->width, (float)this->height};
	Vector2 vector{ player.getX(), player.getY() };

	if (CheckCollisionCircleRec(vector,(float) player.getRad(), rectangle)) {
		player.setAlive(false);
	}

}

void Enemy::checkPlayerAttack(Bullet &bullet) {

	Vector2 bulletVector{ bullet.x, bullet.y };
	Vector2 currentVector{ this->x, this->y };

	if (CheckCollisionCircles(bulletVector, bullet.radius, currentVector, this->width/2)) {
		this->setAlive(false);
	}

}

void Enemy::drawEnemy() {
	DrawRectangle(x,y, width, height, RED);
}