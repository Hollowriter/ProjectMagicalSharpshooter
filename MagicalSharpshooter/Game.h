#pragma once
#include <SFML/Graphics.hpp>
// #include "Tank.h"
#include"Entity.h"

using namespace sf;

class Game {
private:
	RenderWindow* window;
	bool isRunning;
	void _Update(float deltaTime);
	void _Draw();
	// Tank* tank;
public:
	Game();
	virtual ~Game();
	void Run();
};

