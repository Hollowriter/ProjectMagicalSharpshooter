#pragma once
#include "Entity.h"
#define ENEMYSPEED 100.0f
#define ENEMYHEALTH 1;
class Enemy : public Entity
{
private:
	Texture texture;
	Vector2f velocity;
	int health;
	float speed;
	void Movement(float deltaTime);
public:
	Enemy();
	Enemy(int _health, float _speed, string textureName);
	~Enemy();
};

