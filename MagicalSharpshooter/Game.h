#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Enemy.h"
#include"CollisionManager.h"
#include"BulletPool.h"
#include"Tileset.h"

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
	Tileset* tileSet;
	sf::View* camera;
	void UpdateEnemyPositioning();
	void CheckPlayerEnemyCollsions();
	void CheckEnemiesBulletCollisions();
	void UpdateCameraPosition();
public:
	Game();
	virtual ~Game();
	void Run();
};

