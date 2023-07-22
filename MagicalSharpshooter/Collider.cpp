#include "Collider.h"

Collider::Collider() : Entity("Collider")
{
	isSolid = false;
}

Collider::Collider(float posX, float posY, float width, float height) : Entity("Collider")
{
	setPosition(posX, posY);
	setScale(width, height);
	isSolid = false;
}

Collider::Collider(float posX, float posY, float width, float height, bool _isSolid) : Entity("Collider")
{
	setPosition(posX, posY);
	setScale(width, height);
	isSolid = _isSolid;
}

Collider::Collider(bool _isSolid) : Entity("Collider")
{
	isSolid = _isSolid;
}

Collider::~Collider()
{
}

void Collider::Update(float deltaTime)
{
}

void Collider::UpdateEntityComponentPositions()
{
}

bool Collider::GetIsSolid()
{
	return isSolid;
}
