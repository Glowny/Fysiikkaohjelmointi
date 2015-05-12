#include "Entity.h"


Entity::Entity()
{
	currentSpeed = sf::Vector2f(0.0f,0.0f);
	nextSpeed = sf::Vector2f(0.0f, 0.0f);
}


Entity::~Entity()
{
}

void Entity::SetPosition(sf::Vector2f position)
{
	currentPosition = position;
	sprite.setPosition(position);
	SetNextPosition(position);
}

void Entity::SetSpeed(sf::Vector2f speed)
{
	currentSpeed = speed;
	SetNextSpeed(speed);
}

void Entity::SetNextPosition(sf::Vector2f position)
{
	nextPosition = position;
}

void Entity::SetNextSpeed(sf::Vector2f speed)
{
	nextSpeed = speed;
}

sf::Vector2f Entity::GetPosition()
{
	return currentPosition;
}

sf::Vector2f Entity::GetSpeed()
{
	return currentSpeed;
}

sf::Vector2f Entity::GetNextPosition()
{
	return nextPosition;
}

sf::Vector2f Entity::GetNextSpeed()
{
	return nextSpeed;
}

sf::Vector2f* Entity::GetCurrentPositionPointer()
{
	return &currentPosition;
}
sf::Vector2f* Entity::GetNextPositionPointer()
{
	return &nextPosition;
}

sf::Vector2f* Entity::GetCurrentSpeedPointer()
{
	return &currentSpeed;
}
sf::Vector2f* Entity::GetNextSpeedPointer()
{
	return &nextSpeed;
}

sf::Sprite* Entity::GetSprite()
{
	return &sprite;
}