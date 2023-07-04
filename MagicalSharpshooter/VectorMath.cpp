#include "VectorMath.h"

sf::Vector2f VectorMath::Interpolate(const sf::Vector2f pointA, const sf::Vector2f pointB, float factor)
{
	if (factor > 1.f)
		factor = 1.f;
	else if (factor < 0.f)
		factor = 0.f;
	return pointA + (pointB - pointA) * factor;
}
