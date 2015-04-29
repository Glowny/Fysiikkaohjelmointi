#include "MouseCoordinateWrapper.h"


sf::Window* MouseCoordinateWrapper::window;

sf::Vector2f MouseCoordinateWrapper::GetMousePosition()
{
	sf::Vector2i tempVec = sf::Mouse::getPosition((*window));
	return sf::Vector2f(tempVec.x, tempVec.y);
}

void MouseCoordinateWrapper::Initialize(sf::Window* relativeTo)
{
	window = relativeTo;
}