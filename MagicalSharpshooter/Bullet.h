#pragma once
#include "Entity.h"
#include "StateEnums.h"
#define STANDARDBULLETSPEED 100
class Bullet : public Entity
{
private:
	int speed;
	Texture texture;
	Vector2f velocity;
	LookDirection direction;
	void Advance(float deltaTime);
public:
	Bullet();
	~Bullet();
	void Update(float deltaTime) override;
	void UpdateEntityComponentPositions() override;
	void ResolveCollisions(string _collisionName) override;
	void ShootBullet(Vector2f newPosition, LookDirection newDirection);
};
