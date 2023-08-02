#include "CollisionManager.h"

bool CollisionManager::IsColliding(sf::FloatRect col1, sf::FloatRect col2)
{
    if (col1.intersects(col2))
        return true;
    return false;
}

bool CollisionManager::IsCollidingObject(Entity& col1, Entity& col2, std::string colName1, std::string colName2)
{
    if (col1.GetActive() && col2.GetActive()) 
    {
        if (col1.getGlobalBounds().intersects(col2.getGlobalBounds()))
            if (col1.GetName() == colName1 && col2.GetName() == colName2)
                return true;
    }
    return false;
}

void CollisionManager::CollisionWithResolution(Entity& col1, Entity& col2, std::string colName1, std::string colName2)
{
    if (col1.GetActive() && col2.GetActive()) 
    {
        if (col1.getGlobalBounds().intersects(col2.getGlobalBounds())) 
        {
            if (col1.GetName() == colName1 && col2.GetName() == colName2)
            {
                col1.ResolveCollisions(colName2);
                col2.ResolveCollisions(colName1);
            }
        }
    }
}
