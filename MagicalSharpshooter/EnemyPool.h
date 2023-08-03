#pragma once
#include"Enemy.h"
#define STANDARDPOOLSIZE 50
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
	list<Enemy*>* GetEnemyList();
};

