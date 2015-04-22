#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
class Box
{
public:
	Box(sf::RenderWindow* window, sf::FloatRect rectangle);
	~Box();

	virtual void Draw(){};
	virtual void Update(){};
protected:
	sf::RenderWindow* window;
	sf::FloatRect globalRectangle;
	sf::FloatRect localRectangle;
	sf::RenderStates state;
};

