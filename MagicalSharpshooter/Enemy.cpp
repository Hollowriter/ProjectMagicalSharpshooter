#include "Enemy.h"

void Enemy::Movement(float deltaTime)
{
	// Make it move towards player
}

Enemy::Enemy() : Entity("Enemy")
{
	texture.loadFromFile("Resources/Textures/EvilBall.png");
	setTexture(texture);
	speed = ENEMYSPEED;
	health = ENEMYHEALTH;
}

Enemy::Enemy(int _health, float _speed, string textureName) : Entity("Enemy")
{
	texture.loadFromFile(textureName);
	setTexture(texture);
	speed = _speed;
	health = _speed;
}

Enemy::~Enemy()
{
}
