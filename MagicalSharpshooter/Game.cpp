#include "Game.h"

void Game::_Update(float deltaTime)
{
    EntityManager::GetInstance()->UpdateEntities(deltaTime);
    testEnemy->LookAtObjective(girl->getPosition());
}

void Game::_Draw()
{
    window->clear(Color::Cyan);
    for (Entity* entity : EntityManager::GetInstance()->GetEntities())
    {
        window->draw(*entity);
    }
    window->display();

}

Game::Game() {
    window = new RenderWindow(sf::VideoMode(800, 600), "My window");
    girl = new Player();
    testEnemy = new Enemy();
    testEnemy->setPosition(200, 50);
    isRunning = true;
}

Game::~Game() {
    if (window)
    {
        delete window;
        delete girl;
        delete testEnemy;
        window = nullptr;
    }
}

void Game::Run() {

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