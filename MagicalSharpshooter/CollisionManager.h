#pragma once
#include"VectorMath.h"
#include"Collider.h"
#include <SFML/Graphics.hpp>
class CollisionManager
{
public:
	static bool IsColliding(sf::FloatRect col1, sf::FloatRect col2);
	static bool IsCollidingObject(Entity& entity1, Entity& entity2);
};
