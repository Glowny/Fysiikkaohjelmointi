#include "DemoBox.h"

DemoBox::DemoBox(sf::RenderWindow* window, sf::FloatRect rectangle) : Box(window, rectangle)
{
	origo = sf::Vector2f(390, 600);
	state.transform = state.transform.translate(origo);
}


DemoBox::~DemoBox()
{
}

void DemoBox::Draw()
{
	for (int i = 0; i < drawVector.size(); i++)
	{
		window->draw(*drawVector[i], state);
	}
}