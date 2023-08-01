#pragma once
#include"Bullet.h"
#define STANDARDPOOLSIZE 100
class BulletPool
{
private:
	static BulletPool* instance;
	list<Bullet*>* bullets;
	BulletPool();
	~BulletPool();
public:
	static BulletPool* GetInstance() {
		if (instance == nullptr)
		{
			instance = new BulletPool();
		}
		return instance;
	}
	void CallBullet(Vector2f bulletOrigin, LookDirection originDirection);
};
