#pragma once
#include"Entity.h"
class Collider
{
private:
	sf::Vector2f position;
	sf::Vector2f size;
	bool isSolid;
public:
	Collider();
	Collider(sf::Vector2f _position, sf::Vector2f _size);
	Collider(sf::Vector2f _position, sf::Vector2f _size, bool _isSolid);
	Collider(bool _isSolid);
	~Collider();
	void SetPosition(sf::Vector2f _position);
	void SetSize(sf::Vector2f _size);
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	sf::Rect<float> GetRect();
	bool GetIsSolid();
};
