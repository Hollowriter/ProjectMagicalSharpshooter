#include "CollisionManager.h"

bool CollisionManager::IsColliding(sf::FloatRect col1, sf::FloatRect col2)
{
    if (col1.intersects(col2))
        return true;
    return false;
}

bool CollisionManager::IsCollidingObject(Entity& col1, Entity& col2, std::string colName1, std::string colName2)
{
   /* if (col1.GetRect().intersects(col2.GetRect()))
        if (col1.GetObjectAttachedName() == colName1 && col2.GetObjectAttachedName() == colName2)
            return true;*/
    if (col1.getGlobalBounds().intersects(col2.getGlobalBounds()))
        if (col1.GetName() == colName1 && col2.GetName() == colName2)
            return true;
    return false;
}