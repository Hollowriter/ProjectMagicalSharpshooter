#include "CollisionManager.h"

bool CollisionManager::IsColliding(sf::FloatRect col1, sf::FloatRect col2)
{
    if (col1.intersects(col2))
        return true;
    return false;
}

bool CollisionManager::IsCollidingObject(Entity& entity1, Entity& entity2)
{
    return false; // Create a collider in all entities. (Hollow)
}
