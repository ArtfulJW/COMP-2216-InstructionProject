#pragma once
#include "Player.h"
#include "math.h"

class Enemy {
public:
	float x;
	float y;
	int width;
	int height;

	// Constructor
	Enemy(float, float);

	bool getAlive();
	void setAlive(bool);

	// Functions
	void drawEnemy();
	void moveEnemy(Player);
	void checkCollidePlayer(Player&);
	void checkPlayerAttack(Bullet&);

private:
	bool alive;
};