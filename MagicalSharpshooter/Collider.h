#pragma once
#include"Entity.h"
class Collider : public Entity
{
private:
	bool isSolid;
public:
	Collider();
	Collider(float posX, float posY, float width, float height);
	Collider(float posX, float posY, float width, float height, bool _isSolid);
	Collider(bool _isSolid);
	~Collider();
	void Update(float deltaTime) override;
	void UpdateEntityComponentPositions() override;
	bool GetIsSolid();
};
