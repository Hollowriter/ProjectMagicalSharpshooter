#pragma once
#include "Entity.h"
#define PLAYERSPEED 200.0f
#define PLAYERHEALTH 5;
class Player : public Entity
{
private:
	Texture texture;
	Vector2f velocity;
	float speed;
	int health;
	void Attack();
	void Movement(float deltaTime);
public:
	Player();
	Player(float _speed, int _health, string textureName);
	~Player();
	void Damaged(float damageReceived);
	void Update(float deltaTime) override;
};

