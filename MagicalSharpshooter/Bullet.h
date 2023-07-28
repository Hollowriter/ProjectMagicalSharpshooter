#pragma once
#include "Entity.h"
#include "StateEnums.h"
#define STANDARDBULLETSPEED 5
class Bullet : public Entity
{
private:
	int speed;
	void Advance();
	LookDirection direction;
public:
	Bullet();
	~Bullet();
	void Update(float deltaTime) override;
	void UpdateEntityComponentPositions() override;
	void ResolveCollisions(string _collisionName) override;
};

