#include "Entity.h"

Entity::Entity(std::string name) : Sprite()
{
	this->name = name;
	active = true;
	EntityManager::GetInstance()->AddEntity(this);
}

Entity::~Entity()
{
}

void Entity::SetActive(bool _active)
{
	active = _active;
}

bool Entity::GetActive()
{
	return active;
}
