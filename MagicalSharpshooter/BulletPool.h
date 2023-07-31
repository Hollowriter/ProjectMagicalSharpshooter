#pragma once
#include"Bullet.h"
#define STANDARDPOOLSIZE 100
class BulletPool
{
private:
	list<Bullet*>* bullets;
public:
	BulletPool();
	BulletPool(int poolSize);
	~BulletPool();
	void CallBullet(Vector2f bulletOrigin, LookDirection originDirection);
};
