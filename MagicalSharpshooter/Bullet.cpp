#include "Bullet.h"

void Bullet::Advance(float deltaTime)
{
	velocity = Vector2f();
	if (direction == LookDirection::LEFT)
	{
		velocity.x = -speed;
	}
	if (direction == LookDirection::RIGHT)
	{
		velocity.x = speed;
	}
	if (direction == LookDirection::UP)
	{
		velocity.y = -speed;
	}
	if (direction == LookDirection::DOWN)
	{
		velocity.y = speed;
	}
	move(velocity * deltaTime);
}

void Bullet::KillBullet()
{
	timer = 0;
	SetActive(false);
}

void Bullet::TimeTicking(float deltaTime)
{
	timer += deltaTime;
	if (timer > TIMEALIVE)
		KillBullet();
}

Bullet::Bullet() : Entity("Bullet")
{
	texture.loadFromFile("Resources/Textures/Bullet.png");
	setTexture(texture);
	speed = STANDARDBULLETSPEED;
	direction = LookDirection::DOWN;
	timer = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
	if (GetActive()) 
	{
		Advance(deltaTime);
		TimeTicking(deltaTime);
	}
		
}

void Bullet::UpdateEntityComponentPositions()
{
}

void Bullet::ResolveCollisions(string _collisionName)
{
	// Make collisions to the enemy
}

void Bullet::ShootBullet(Vector2f newPosition, LookDirection newDirection)
{
	SetActive(true);
	setPosition(newPosition);
	direction = newDirection;
}
