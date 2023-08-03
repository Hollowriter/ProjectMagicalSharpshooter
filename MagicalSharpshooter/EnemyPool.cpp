#include "EnemyPool.h"

EnemyPool::EnemyPool()
{
    enemies = new list<Enemy*>();
    for (int i = 0; i < STANDARDPOOLSIZE; i++)
    {
        enemies->push_back(new Enemy());
        enemies->back()->SetActive(false);
    }
}

EnemyPool::~EnemyPool()
{
    std::list<Enemy*>::iterator it;
    for (it = enemies->begin(); it != enemies->end(); ++it)
    {
        delete (*it);
    }
    enemies->clear();
    delete enemies;
}

list<Enemy*>* EnemyPool::GetEnemyList()
{
	return enemies;
}
