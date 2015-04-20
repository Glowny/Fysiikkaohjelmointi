#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
class Box
{
public:
	Box(sf::Window* window);
	~Box();

	virtual void Draw(){};
	virtual void Update(){};
protected:
	sf::Window* window;
	sf::Vector2i coordinates;
	sf::Vector2i size;
};

