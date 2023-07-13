#include "Enemy.h"

void Enemy::Movement(float deltaTime)
{
	if (objectiveSet)
	{
		setPosition(math.Interpolate<sf::Vector2f>(getPosition(), objective, speed * deltaTime));
	}
}

Enemy::Enemy() : Entity("Enemy")
{
	texture.loadFromFile("Resources/Textures/EvilBall.png");
	setTexture(texture);
	speed = ENEMYSPEED;
	health = ENEMYHEALTH;
	objectiveSet = false;
}

Enemy::Enemy(int _health, float _speed, string textureName) : Entity("Enemy")
{
	texture.loadFromFile(textureName);
	setTexture(texture);
	speed = _speed;
	health = _health;
	objectiveSet = false;
}

Enemy::~Enemy()
{
}

void Enemy::Damaged(int damageReceived)
{
	health -= damageReceived;
}

void Enemy::Update(float deltaTime)
{
	Movement(deltaTime);
}

void Enemy::LookAtObjective(Vector2f _objective)
{
	objective = _objective;
	objectiveSet = true;
}
