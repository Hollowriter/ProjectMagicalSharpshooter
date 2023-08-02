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
	void _Update(float deltaTime);
	void _Draw();
	Player* girl;
	Enemy* testEnemy;
	BulletPool* bulletPool;
	void UpdateEnemyPositioning();
	void CheckPlayerEnemyCollsions();
	void CheckEnemiesBulletCollisions();
public:
	Game();
	virtual ~Game();
	void Run();
};

