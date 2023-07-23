#include "Collider.h"

Collider::Collider()
{
	isSolid = false;
}

Collider::Collider(sf::Vector2f _position, sf::Vector2f _size)
{
	position = _position;
	size = _size;
	isSolid = false;
}

Collider::Collider(sf::Vector2f _position, sf::Vector2f _size, bool _isSolid)
{
	position = _position;
	size = _size;
	isSolid = _isSolid;
	cout << position.x << " " << position.y << " " << size.x << " " << size.y << endl;
}

Collider::Collider(bool _isSolid)
{
	isSolid = _isSolid;
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

bool Collider::GetIsSolid()
{
	return isSolid;
}
