#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class VectorMath // Note: Check to make this a library
{
public:
	template<typename T>
	T Interpolate(T pointA, T pointB, float factor)
	{
		if (factor > 1.f)
			factor = 1.f;
		else if (factor < 0.f)
			factor = 0.f;
		return pointA + (pointB - pointA) * factor;
	}
	//sf::Vector2f Interpolate(sf::Vector2f pointA, sf::Vector2f pointB, float factor);
};

