#pragma once
#include <SFML\System.hpp>
#include "SFML\Graphics.hpp"
class Entity
{
public:
	Entity();
	~Entity();
	
	void SetPosition(sf::Vector2f position);
	void SetSpeed(sf::Vector2f speed);
	void SetNextPosition(sf::Vector2f position);

	sf::Vector2f GetPosition();
	sf::Vector2f GetSpeed();
	sf::Vector2f GetNextPosition();
	sf::Sprite* GetSprite();

protected:
	sf::Vector2f currentPosition;
	sf::Vector2f speed;

	sf::Vector2f nextPosition;

	sf::Sprite sprite;
};

