#include "Game.h"

void Game::_Update(float deltaTime)
{
    EntityManager::GetInstance()->UpdateEntities(deltaTime);
    UpdateEnemyPositioning();
    CheckPlayerEnemyCollsions();
    CheckEnemiesBulletCollisions();
}

void Game::_Draw()
{
    window->clear(Color::Cyan);
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

Game::Game()
{
    window = new RenderWindow(sf::VideoMode(800, 600), "My window");
    girl = new Player();
    testEnemy = new Enemy();
    testEnemy->setPosition(200, 50);
    isRunning = true;
    bulletPool = BulletPool::GetInstance();
}

Game::~Game() 
{
    if (window)
    {
        delete girl;
        delete testEnemy;
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

        _Update(deltaTime);
        _Draw();
    }
}