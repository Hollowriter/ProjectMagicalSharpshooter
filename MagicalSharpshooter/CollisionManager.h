#pragma once
#include"VectorMath.h"
#include"Collider.h"
#include <SFML/Graphics.hpp>
class CollisionManager
{
public:
	static bool IsColliding(sf::FloatRect col1, sf::FloatRect col2);
	static bool IsCollidingObject(Entity& col1, Entity& col2, std::string colName1, std::string colName2);
};
