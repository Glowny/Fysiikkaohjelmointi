#include "Box.h"


Box::Box(sf::RenderWindow* window, sf::FloatRect rectangle)
{
	this->window = window;
	globalRectangle = rectangle;
	state = sf::RenderStates::Default;
	sf::Transform tempTransform;
	tempTransform.translate(rectangle.left, rectangle.top);
	state.transform = tempTransform;
}

Box::~Box()
{
}

