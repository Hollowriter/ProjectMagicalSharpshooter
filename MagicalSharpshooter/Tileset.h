#pragma once
#include<vector>
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;
class Tileset : public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray tileSetVertices;
	sf::Texture tileSetTex;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &tileSetTex;
        target.draw(tileSetVertices, states);
    }
public:
	Tileset();
	~Tileset();
	void LoadMap(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};

