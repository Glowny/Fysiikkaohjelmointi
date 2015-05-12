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
	void SetNextSpeed(sf::Vector2f speed);

	sf::Vector2f GetPosition();
	sf::Vector2f GetSpeed();
	sf::Vector2f GetNextPosition();
	sf::Vector2f GetNextSpeed();

	sf::Vector2f* GetCurrentPositionPointer();
	sf::Vector2f* GetNextPositionPointer();

	sf::Vector2f* GetCurrentSpeedPointer();
	sf::Vector2f* GetNextSpeedPointer();

	sf::Sprite* GetSprite();

protected:
	sf::Vector2f currentPosition;
	sf::Vector2f currentSpeed;

	sf::Vector2f nextPosition;
	sf::Vector2f nextSpeed;

	sf::Sprite sprite;
};

