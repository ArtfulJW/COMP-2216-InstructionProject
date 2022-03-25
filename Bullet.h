#pragma once
#include "Math.h"

class Bullet {
public:
	float x;
	float y;
	float dest_x;
	float dest_y;
	bool gotDest;
	bool reachDest;
	float radius;

	//Constructor
	Bullet(float, float);

	// Getter
	bool getReachDest();

	// Functions
	void update();
	void getMouseCoord();
	void calcBullet();
	void drawBullet();

private:
};