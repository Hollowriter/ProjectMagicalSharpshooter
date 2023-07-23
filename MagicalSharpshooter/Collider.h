#pragma once
#include"Entity.h"
class Collider
{
private:
	sf::Vector2f position;
	sf::Vector2f size;
	std::string objectAttached;
	bool isSolid;
public:
	Collider();
	Collider(sf::Vector2f _position, sf::Vector2f _size, std::string _objectAttached);
	Collider(sf::Vector2f _position, sf::Vector2f _size, std::string _objectAttached, bool _isSolid);
	Collider(std::string _objectAttached, bool _isSolid);
	~Collider();
	void SetPosition(sf::Vector2f _position);
	void SetSize(sf::Vector2f _size);
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	sf::Rect<float> GetRect();
	std::string GetObjectAttachedName();
	bool GetIsSolid();
};
