#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Enemy.h"
#include"CollisionManager.h"
#include"BulletPool.h"
#include"EnemyPool.h"
#include"Tileset.h"

using namespace sf;

class Game {
private:
	RenderWindow* window;
	bool isRunning;
	bool isGameFinished;
	void _Update(float deltaTime);
	void _Draw();
	Player* girl;
	EnemyPool* enemyPool;
	BulletPool* bulletPool;
	Tileset* tileSet;
	sf::View* camera;
	sf::Font* font;
	sf::Text gameOverText;
	const float ENDGAMETIME = 3;
	float timer;
	void UpdateEnemyPositioning();
	void CheckPlayerEnemyCollsions();
	void CheckEnemiesBulletCollisions();
	void UpdateCameraPosition();
	void CheckGameEnd();
	void CheckGameClose(float deltaTime);
public:
	Game();
	virtual ~Game();
	void Run();
};

