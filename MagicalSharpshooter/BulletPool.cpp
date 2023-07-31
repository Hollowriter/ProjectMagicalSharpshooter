#include "BulletPool.h"

BulletPool::BulletPool()
{
    bullets = new list<Bullet*>();
    for (int i = 0; i < STANDARDPOOLSIZE; i++)
    {
        bullets->push_back(new Bullet());
        bullets->back()->SetActive(false);
    }
}

BulletPool::BulletPool(int poolSize)
{
    bullets = new list<Bullet*>();
    for (int i = 0; i < poolSize; i++)
    {
        bullets->push_back(new Bullet());
        bullets->back()->SetActive(false);
    }
}

BulletPool::~BulletPool()
{
    std::list<Bullet*>::iterator it;
    for (it = bullets->begin(); it != bullets->end(); ++it) {
        delete (*it);
    }
    bullets->clear();
    delete bullets;
}

void BulletPool::CallBullet(Vector2f bulletOrigin, LookDirection originDirection)
{
    std::list<Bullet*>::iterator it;
    for (it = bullets->begin(); it != bullets->end(); ++it) {
        if (!(*it)->GetActive())
        {
            (*it)->ShootBullet(bulletOrigin, originDirection);
        }
    }
}
