#include "Entity.h"


Entity::Entity()
{
	speed = sf::Vector2f(0.0f,0.0f);
}


Entity::~Entity()
{
}

void Entity::SetPosition(sf::Vector2f position)
{
	currentPosition = position;
	sprite.setPosition(position);
}

void Entity::SetSpeed(sf::Vector2f speed)
{
	this->speed = speed;
}

void Entity::SetNextPosition(sf::Vector2f position)
{
	nextPosition = position;
}

sf::Vector2f Entity::GetPosition()
{
	return currentPosition;
}

sf::Vector2f Entity::GetSpeed()
{
	return speed;
}

sf::Vector2f Entity::GetNextPosition()
{
	return nextPosition;
}

sf::Sprite* Entity::GetSprite()
{
	return &sprite;
}