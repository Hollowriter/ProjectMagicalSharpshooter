#include "EnemyPool.h"

EnemyPool* EnemyPool::instance = nullptr;

EnemyPool::EnemyPool()
{
    enemies = new list<Enemy*>();
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

void EnemyPool::GenerateEnemies(int enemyQuantity, int xOffset, int yOffset, int positionXRange, int positionYRange)
{
    int randomX = 0;
    int randomY = 0;
    for (int i = 0; i < enemyQuantity; i++)
    {
        randomX = xOffset + (rand() % positionXRange);
        randomY = yOffset + (rand() % positionYRange);
        enemies->push_back(new Enemy());
        enemies->back()->setPosition(randomX, randomY);
    }
}

list<Enemy*>* EnemyPool::GetEnemyList()
{
	return enemies;
}

int EnemyPool::GetEnemiesActive()
{
    int activeEnemies = 0;
    std::list<Enemy*>::iterator it;
    for (it = enemies->begin(); it != enemies->end(); ++it)
    {
        if ((*it)->GetActive())
            activeEnemies++;

    }
    return activeEnemies;
}
