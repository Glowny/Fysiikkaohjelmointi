#include "Physics.h"

const float Physics::gravityAcceleration = 981;
const float Physics::deltaTime = 1.0f/120.0f;

void Physics::GravityFunc(Entity* entity)
{
	entity->SetSpeed(sf::Vector2f(entity->GetSpeed().x, UpdateSpeed(entity->GetSpeed().y, gravityAcceleration)));
	entity->SetNextPosition(sf::Vector2f(entity->GetPosition().x, UpdatePosition(entity->GetPosition().y,entity->GetSpeed().y, gravityAcceleration)));
	entity->SetPosition(entity->GetNextPosition());
}

float Physics::UpdateSpeed(float speed, float acceleration)
{
	return (speed + acceleration * deltaTime);
}

float Physics::UpdatePosition(float position, float speed, float acceleration)
{
	return (position + speed * deltaTime + 1 / 2 * acceleration * deltaTime * deltaTime);
}

float Physics::InelasticCollision(float speed, float restitution)
{
	return(-restitution*speed);
}