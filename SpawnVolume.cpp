#include "raylib.h"
#include "SpawnVolume.h"
#include "Enemy.h"

SpawnVolume::SpawnVolume(int width, int height) {
	this->width = width;
	this->height = height;
}

void SpawnVolume::spawnEnemy(std::vector<Enemy> &enemyList){
	if (GetRandomValue(0,100) >= 95) {
		Enemy newEnemy(GetRandomValue(0, width), GetRandomValue(0, height));
		enemyList.push_back(newEnemy);
	}
}
