#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class MouseCoordinateWrapper
{
public:
	static sf::Vector2f GetMousePosition();
	static void Initialize(sf::Window* relativeTo);
private:
	static sf::Window* window;
};

