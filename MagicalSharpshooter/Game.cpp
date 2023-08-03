#include "Game.h"

void Game::_Update(float deltaTime)
{
    EntityManager::GetInstance()->UpdateEntities(deltaTime);
    UpdateEnemyPositioning();
    CheckPlayerEnemyCollsions();
    CheckEnemiesBulletCollisions();
    UpdateCameraPosition();
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
    window->display();
}

void Game::UpdateEnemyPositioning()
{
    testEnemy->LookAtObjective(girl->getPosition());
}

void Game::CheckPlayerEnemyCollsions()
{
    //CollisionManager::CollisionWithResolution(*girl, *testEnemy, "Player", "Enemy");
}

void Game::CheckEnemiesBulletCollisions()
{
    std::list<Bullet*>::iterator it;
    for (it = bulletPool->GetBulletList()->begin(); it != bulletPool->GetBulletList()->end(); ++it)
    {
        CollisionManager::CollisionWithResolution(*testEnemy, *(*it), "Enemy", "Bullet");
    }
}

void Game::UpdateCameraPosition()
{
    camera->setCenter(girl->getPosition());
}

Game::Game()
{
    window = new RenderWindow(sf::VideoMode(1000, 1000), "My window");
    girl = new Player();
    testEnemy = new Enemy();
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
    testEnemy->setPosition(200, 50);
    camera->setSize(800, 300);
    camera->setCenter(girl->getPosition());
    window->setView(*camera);
    isRunning = true;
    bulletPool = BulletPool::GetInstance();
}

Game::~Game() 
{
    if (window)
    {
        delete girl;
        delete testEnemy;
        delete tileSet;
        delete camera;
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