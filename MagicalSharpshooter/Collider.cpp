#include "Collider.h"

Collider::Collider()
{
	isSolid = false;
	objectAttached = "collider";
}

Collider::Collider(sf::Vector2f _position, sf::Vector2f _size, std::string _objectAttached)
{
	position = _position;
	size = _size;
	isSolid = false;
	objectAttached = _objectAttached;
}

Collider::Collider(sf::Vector2f _position, sf::Vector2f _size, std::string _objectAttached, bool _isSolid)
{
	position = _position;
	size = _size;
	isSolid = _isSolid;
	objectAttached = _objectAttached;
}

Collider::Collider(std::string _objectAttached, bool _isSolid)
{
	isSolid = _isSolid;
	objectAttached = _objectAttached;
}

Collider::~Collider()
{
}

void Collider::SetPosition(sf::Vector2f _position)
{
	position = _position;
}

void Collider::SetSize(sf::Vector2f _size)
{
	size = _size;
}

sf::Vector2f Collider::GetPosition()
{
	return position;
}

sf::Vector2f Collider::GetSize()
{
	return size;
}

sf::Rect<float> Collider::GetRect()
{
	return sf::Rect<float>(position, size);
}

std::string Collider::GetObjectAttachedName()
{
	return objectAttached;
}

bool Collider::GetIsSolid()
{
	return isSolid;
}
