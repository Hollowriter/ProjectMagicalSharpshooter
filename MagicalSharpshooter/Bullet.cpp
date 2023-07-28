#include "Bullet.h"

void Bullet::Advance()
{
}

Bullet::Bullet() : Entity("Bullet")
{
	speed = STANDARDBULLETSPEED;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
	Advance();
}

void Bullet::UpdateEntityComponentPositions()
{
}

void Bullet::ResolveCollisions(string _collisionName)
{
	// Make collisions to the enemy
}
