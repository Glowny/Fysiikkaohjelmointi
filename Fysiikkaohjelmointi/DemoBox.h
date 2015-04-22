#pragma once
#include "Box.h"
#include "Entity.h"
#include <vector>
class DemoBox:public Box
{
public:
	DemoBox(sf::RenderWindow* window, sf::FloatRect rectangle);
	~DemoBox();
	void Draw();
	std::vector<sf::Sprite*> drawVector;

	sf::Vector2f origo;
};
