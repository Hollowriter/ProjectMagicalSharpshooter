#pragma once
#include"Enemy.h"
class EnemyPool
{
private:
	static EnemyPool* instance;
	list<Enemy*>* enemies;
	EnemyPool();
	~EnemyPool();
public:
	static EnemyPool* GetInstance() {
		if (instance == nullptr)
		{
			instance = new EnemyPool();
		}
		return instance;
	}
	void GenerateEnemies(int enemyQuantity, int xOffset, int yOffset, int positionXRange, int positionYRange);
	list<Enemy*>* GetEnemyList();
	int GetEnemiesActive();
};

