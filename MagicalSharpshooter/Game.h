#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Enemy.h"

using namespace sf;

class Game {
private:
	RenderWindow* window;
	bool isRunning;
	void _Update(float deltaTime);
	void _Draw();
	Player* girl;
	Enemy* testEnemy;
public:
	Game();
	virtual ~Game();
	void Run();
};

