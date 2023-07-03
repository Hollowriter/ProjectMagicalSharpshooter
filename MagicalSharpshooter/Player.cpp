#include "Player.h"

void Player::Attack()
{
}

void Player::Movement(float deltaTime)
{
	velocity = Vector2f();
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		velocity.x = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		velocity.x = speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		velocity.y = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		velocity.y = speed;
	}
	move(velocity * deltaTime);
}

Player::Player() : Entity("Player")
{
	texture.loadFromFile("Resources/Textures/Sharla.png");
	setTexture(texture);
	speed = PLAYERSPEED;
	health = PLAYERHEALTH;
}

Player::Player(float _speed, int _health, string textureName) : Entity("Player")
{
	texture.loadFromFile(textureName);
	setTexture(texture);
	speed = _speed;
	health = _health;
}

Player::~Player()
{
}

void Player::Damaged(float damageReceived)
{
	health -= damageReceived;
}

void Player::Update(float deltaTime)
{
	Movement(deltaTime);
}
