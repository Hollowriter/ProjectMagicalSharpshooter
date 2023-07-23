#include "CollisionManager.h"

bool CollisionManager::isColliding(sf::FloatRect col1, sf::FloatRect col2)
{
    if (col1.intersects(col2))
        return true;
    return false;
}
