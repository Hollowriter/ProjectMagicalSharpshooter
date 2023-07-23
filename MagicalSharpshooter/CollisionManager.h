#pragma once
#include"VectorMath.h"
#include"Collider.h"
#include <SFML/Graphics.hpp>
class CollisionManager
{
public:
	static bool isColliding(sf::FloatRect col1, sf::FloatRect col2);
};
