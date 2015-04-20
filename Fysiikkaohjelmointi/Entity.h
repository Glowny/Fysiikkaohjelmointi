#pragma once
#include <SFML\System.hpp>
class Entity
{
public:
	Entity();
	~Entity();
	virtual void Update(){};
	sf::Vector2f coordinates;
};

