#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class VectorMath // Note: Check to make this a library
{
public:
	sf::Vector2f Interpolate(const sf::Vector2f pointA, const sf::Vector2f pointB, float factor);
};

