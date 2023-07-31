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
		direction = LookDirection::LEFT;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		velocity.x = speed;
		direction = LookDirection::RIGHT;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		velocity.y = -speed;
		direction = LookDirection::UP;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		velocity.y = speed;
		direction = LookDirection::DOWN;
	}
	move(velocity * deltaTime);
}

Player::Player() : Entity("Player")
{
	texture.loadFromFile("Resources/Textures/Sharla.png");
	setTexture(texture);
	speed = PLAYERSPEED;
	health = PLAYERHEALTH;
	direction = LookDirection::DOWN;
	collider = new Collider(this->getPosition(), this->getGlobalBounds().getSize(), "Player", false);
}

Player::Player(float _speed, int _health, string textureName) : Entity("Player")
{
	texture.loadFromFile(textureName);
	setTexture(texture);
	speed = _speed;
	health = _health;
	direction = LookDirection::DOWN;
	collider = new Collider(this->getPosition(), this->getGlobalBounds().getSize(), "Player", false);
}

Player::~Player()
{
	delete collider;
}

void Player::Damaged(float damageReceived)
{
	health -= damageReceived;
}

void Player::Update(float deltaTime)
{
	Movement(deltaTime);
	UpdateEntityComponentPositions();
}

void Player::UpdateEntityComponentPositions()
{
	collider->SetPosition(this->getPosition());
}

void Player::ResolveCollisions(string _collisionName)
{
	if (_collisionName == "Enemy") 
	{
		Damaged(1);
		cout << "conoetumadre" << endl;
	}
}

Collider Player::GetCollider()
{
	return *collider;
}

LookDirection Player::GetDirection()
{
	return direction;
}
