#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"

using namespace sf;

class Entity : public Sprite
{
private:
	string name;
	bool active;
public:
	Entity(string name);
	virtual ~Entity();
	virtual void Update(float deltaTime) = 0;
	void SetActive(bool _active);
	bool GetActive();
};

