#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class VectorMath // Note: Check to make this a library
{
public:
	template<typename T>
	static T Interpolate(T pointA, T pointB, float factor)
	{
		if (factor > 1.f)
			factor = 1.f;
		else if (factor < 0.f)
			factor = 0.f;
		return pointA + (pointB - pointA) * factor;
	}
};

