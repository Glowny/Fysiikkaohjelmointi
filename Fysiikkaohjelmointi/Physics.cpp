#include "Physics.h"

const float Physics::gravityAcceleration = 981;
const float Physics::deltaTime = 1.0f/120.0;

void Physics::GravityFunc(Entity* entity)
{
	entity->SetPosition(entity->GetNextPosition());
	entity->SetSpeed(entity->GetNextSpeed());
	entity->SetNextPosition(sf::Vector2f( UpdatePosition(entity->GetPosition().x, entity->GetSpeed().x, 0), UpdatePosition(entity->GetPosition().y, entity->GetSpeed().y, gravityAcceleration)));
	entity->SetNextSpeed(sf::Vector2f(UpdateSpeed(entity->GetSpeed().x, 0), UpdateSpeed(entity->GetSpeed().y, gravityAcceleration)));
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

void Physics::InelasticObjectCollision(BouncingBallEntity* first, BouncingBallEntity* second)
{
	float tempX = first->GetNextPosition().x - second->GetNextPosition().x;
	float tempY = first->GetNextPosition().y - second->GetNextPosition().y;
	if (tempY > 0)
		tempY *= -1;
	if (tempX > 0)
		tempX *= -1;

	float angle = atan(tempY / tempX);

	float firstNormalSpeedBefore = cos(angle)*first->GetNextSpeed().x + sin(angle)*-first->GetNextSpeed().y;
	float secondNormalSpeedBefore = cos(angle)*second->GetNextSpeed().x + sin(angle)*-second->GetNextSpeed().y;

	float firstNormalSpeedAfter = (first->restitutionMultiplier*second->mass*(secondNormalSpeedBefore - firstNormalSpeedBefore
		) + first->mass*firstNormalSpeedBefore + second->mass*secondNormalSpeedBefore) / (first->mass + second->mass);

	float secondNormalSpeedAfter = (second->restitutionMultiplier*first->mass*(firstNormalSpeedBefore - secondNormalSpeedBefore
		) + first->mass*firstNormalSpeedBefore + second->mass*secondNormalSpeedBefore) / (first->mass + second->mass);

	float tangentAngle = angle;// +(3.1415 / 2);

	float firstTangentSpeed = cos(tangentAngle)*first->GetNextSpeed().x - sin(tangentAngle)*first->GetNextSpeed().y;
	float secondTangentSpeed = cos(tangentAngle)*second->GetNextSpeed().x - sin(tangentAngle)*second->GetNextSpeed().y;

	float firstFinalX = sin(angle)*(firstNormalSpeedAfter + firstTangentSpeed);
	float firstFinalY = cos(angle)*(firstNormalSpeedAfter + firstTangentSpeed);

	float secondFinalX = cos(angle)*(secondNormalSpeedAfter + secondTangentSpeed);
	float secondFinalY = sin(angle)*(secondNormalSpeedAfter + secondTangentSpeed);

	first->SetSpeed(sf::Vector2f(firstFinalX, firstFinalY));
	second->SetSpeed(sf::Vector2f(secondFinalX, secondFinalY));

	first->SetNextPosition(sf::Vector2f(UpdatePosition(first->GetPosition().x, first->GetSpeed().x, 0), UpdatePosition(first->GetPosition().y, first->GetSpeed().y, gravityAcceleration)));
	first->SetNextSpeed(sf::Vector2f(UpdateSpeed(first->GetSpeed().x, 0), UpdateSpeed(first->GetSpeed().y, gravityAcceleration)));
	
	second->SetNextPosition(sf::Vector2f(UpdatePosition(second->GetPosition().x, second->GetSpeed().x, 0), UpdatePosition(second->GetPosition().y, second->GetSpeed().y, gravityAcceleration)));
	second->SetNextSpeed(sf::Vector2f(UpdateSpeed(second->GetSpeed().x, 0), UpdateSpeed(second->GetSpeed().y, gravityAcceleration)));

}