#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Enemy.h"
#include"CollisionManager.h"
#include"BulletPool.h"

using namespace sf;

class Game {
private:
	RenderWindow* window;
	bool isRunning;
	bool testRun; // Only for testing purposes, delete afterwards
	void _Update(float deltaTime);
	void _Draw();
	Player* girl;
	Enemy* testEnemy;
public:
	Game();
	virtual ~Game();
	void Run();
};

