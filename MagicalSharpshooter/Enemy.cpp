#include "Enemy.h"

void Enemy::Movement(float deltaTime)
{
	if (objectiveSet)
	{
		setPosition(VectorMath::Interpolate<sf::Vector2f>(getPosition(), objective, speed * deltaTime));
	}
}

Enemy::Enemy() : Entity("Enemy")
{
	texture.loadFromFile("Resources/Textures/EvilBall.png");
	setTexture(texture);
	speed = ENEMYSPEED;
	health = ENEMYHEALTH;
	objectiveSet = false;
	collider = new Collider(this->getPosition(), this->getGlobalBounds().getSize(), "Enemy", false);
}

Enemy::Enemy(int _health, float _speed, string textureName) : Entity("Enemy")
{
	texture.loadFromFile(textureName);
	setTexture(texture);
	speed = _speed;
	health = _health;
	objectiveSet = false;
	collider = new Collider(this->getPosition(), this->getGlobalBounds().getSize(), "Enemy", false);
}

Enemy::~Enemy()
{
	delete collider;
}

void Enemy::Damaged(int damageReceived)
{
	health -= damageReceived;
}

void Enemy::Update(float deltaTime)
{
	if (GetActive()) 
	{
		Movement(deltaTime);
		UpdateEntityComponentPositions();
	}
}

void Enemy::UpdateEntityComponentPositions()
{
	collider->SetPosition(this->getPosition());
}

void Enemy::ResolveCollisions(string _collisionName)
{
	if (_collisionName == "Bullet") 
	{
		Damaged(1);
		if (health <= 0)
			SetActive(false);
	}
}

void Enemy::LookAtObjective(Vector2f _objective)
{
	objective = _objective;
	objectiveSet = true;
}

Collider Enemy::GetCollider()
{
	return *collider;
}
