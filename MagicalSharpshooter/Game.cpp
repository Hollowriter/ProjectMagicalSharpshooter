#include "Game.h"

void Game::_Update(float deltaTime)
{
    EntityManager::GetInstance()->UpdateEntities(deltaTime);
    UpdateEnemyPositioning();
    CheckPlayerEnemyCollsions();
    CheckEnemiesBulletCollisions();
    UpdateCameraPosition();
    CheckGameEnd();
    CheckGameClose(deltaTime);
}

void Game::_Draw()
{
    window->clear(Color::Cyan);
    window->draw(*tileSet);
    for (Entity* entity : EntityManager::GetInstance()->GetEntities())
    {
        if (entity->GetActive())
            window->draw(*entity);
    }
    window->draw(gameOverText);
    window->display();
}

void Game::UpdateEnemyPositioning()
{
    std::list<Enemy*>::iterator enemiesIt;
    for (enemiesIt = enemyPool->GetEnemyList()->begin(); enemiesIt != enemyPool->GetEnemyList()->end(); ++enemiesIt) 
    {
        (*enemiesIt)->LookAtObjective(girl->getPosition());
    }
}

void Game::CheckPlayerEnemyCollsions()
{
    std::list<Enemy*>::iterator enemiesIt;
    for (enemiesIt = enemyPool->GetEnemyList()->begin(); enemiesIt != enemyPool->GetEnemyList()->end(); ++enemiesIt) 
    {
        CollisionManager::CollisionWithResolution(*girl, *(*enemiesIt), "Player", "Enemy");
    }
}

void Game::CheckEnemiesBulletCollisions()
{
    std::list<Bullet*>::iterator bulletIt;
    std::list<Enemy*>::iterator enemiesIt;
    for (bulletIt = bulletPool->GetBulletList()->begin(); bulletIt != bulletPool->GetBulletList()->end(); ++bulletIt)
    {
        for (enemiesIt = enemyPool->GetEnemyList()->begin(); enemiesIt != enemyPool->GetEnemyList()->end(); ++enemiesIt) 
        {
            CollisionManager::CollisionWithResolution(*(*enemiesIt), *(*bulletIt), "Enemy", "Bullet");
        }
    }
}

void Game::UpdateCameraPosition()
{
    camera->setCenter(girl->getPosition());
}

void Game::CheckGameEnd()
{
    if (!isGameFinished) 
    {
        if (!girl->GetActive())
        {
            isGameFinished = true;
            gameOverText.setFont(*font);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setString("GAME OVER");
            gameOverText.setCharacterSize(30);
            gameOverText.setPosition(girl->getPosition());
        }
        if (enemyPool->GetEnemiesActive() <= 0)
        {
            isGameFinished = true;
            gameOverText.setFont(*font);
            gameOverText.setFillColor(sf::Color::Yellow);
            gameOverText.setString("YOU WIN");
            gameOverText.setCharacterSize(30);
            gameOverText.setPosition(girl->getPosition());
        }
    }
}

void Game::CheckGameClose(float deltaTime)
{
    if (isGameFinished) 
    {
        timer += deltaTime;
        if (timer >= ENDGAMETIME)
            window->close();
    }
}

Game::Game()
{
    srand((unsigned)time(NULL));
    window = new RenderWindow(sf::VideoMode(1000, 1000), "My window");
    girl = new Player();
    tileSet = new Tileset();
    camera = new View();
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 4, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 4, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 4, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    tileSet->LoadMap("Resources/Textures/MagicalGirlTileMap.png", Vector2u(32, 32), level, 26, 22);
    camera->setSize(500, 500);
    camera->setCenter(girl->getPosition());
    window->setView(*camera);
    isRunning = true;
    isGameFinished = false;
    bulletPool = BulletPool::GetInstance();
    enemyPool = EnemyPool::GetInstance();
    enemyPool->GenerateEnemies(15, 250, 100, 700, 500);
    font = new Font();
    font->loadFromFile("Resources/Fonts/mermaid/Mermaid1001.ttf");
}

Game::~Game() 
{
    if (window)
    {
        delete girl;
        delete tileSet;
        delete camera;
        delete font;
        delete window;
        window = nullptr;
    }
}

void Game::Run() 
{
    Clock clockDelta;
    float deltaTime = clockDelta.restart().asSeconds();
    while (window->isOpen() || isRunning)
    {
        deltaTime = clockDelta.restart().asSeconds();
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->setView(*camera);
        _Update(deltaTime);
        _Draw();
    }
}