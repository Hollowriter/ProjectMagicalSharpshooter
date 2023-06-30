#include "Game.h"

void Game::_Update(float deltaTime)
{
    EntityManager::GetInstance()->UpdateEntities(deltaTime);
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
    // tank = new Tank();
    isRunning = true;
}

Game::~Game() {
    if (window)
    {
        delete window;
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