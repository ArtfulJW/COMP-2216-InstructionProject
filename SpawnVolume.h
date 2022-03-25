#pragma once
#include "Enemy.h"
#include "vector"

class SpawnVolume {
public:
	// Member Variables
	int width;
	int height;

	// Constructor
	SpawnVolume(int, int);

	// Functions
	void spawnEnemy(std::vector<Enemy> &);

private:
};