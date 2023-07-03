#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"

using namespace sf;

class Game {
private:
	RenderWindow* window;
	bool isRunning;
	void _Update(float deltaTime);
	void _Draw();
	Player* girl;
public:
	Game();
	virtual ~Game();
	void Run();
};

