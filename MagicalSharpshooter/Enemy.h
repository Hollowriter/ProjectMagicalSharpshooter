#pragma once
#include "Entity.h"
#include"VectorMath.h" // Check to make that a library
#include"Collider.h"
#define ENEMYSPEED 0.5f
#define ENEMYHEALTH 1;
class Enemy : public Entity
{
private:
	Texture texture;
	Vector2f velocity;
	Vector2f objective;
	Collider* collider;
	int health;
	float speed;
	bool objectiveSet;
	void Movement(float deltaTime);
public:
	Enemy();
	Enemy(int _health, float _speed, string textureName);
	~Enemy();
	void Damaged(int damageReceived);
	void Update(float deltaTime) override;
	void UpdateEntityComponentPositions() override;
	void LookAtObjective(Vector2f _objective);
	Collider GetCollider();
};

