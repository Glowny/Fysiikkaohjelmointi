#include "Physics.h"

const float Physics::gravityAcceleration = 9.81;
const float Physics::deltaTime = 1.0f/480.0;

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
	float tempX = first->GetNextPosition().x - second->GetNextPosition().x; // negatiivinen = first vasemmalla
	float tempY = first->GetNextPosition().y - second->GetNextPosition().y; // negatiivinen = first päällä

	//if (tempY > 0)
	//	tempY *= -1;
	//if (tempX > 0)
	//	tempX *= -1;

	float angle = atan(tempY / tempX);
	
	float collisionPositionX = cos(angle) * tempX / 2;
//	if (tempX < 0)
//		collisionPositionX -= second->GetNextPosition().x;
//	else
		collisionPositionX += second->GetNextPosition().x;

		float collisionPositionY = sin(angle) * tempY / 2;

		collisionPositionY += second->GetNextPosition().y;

	float temp1X, temp1Y, temp2X, temp2Y = 0;
	
	if (tempX < 0)
	{
		temp1X = collisionPositionX - cos(angle)*first->radius;
		temp2X = collisionPositionX + cos(angle)*second->radius;
	}
	else
	{
		temp1X = collisionPositionX + cos(angle)*first->radius;
		temp2X = collisionPositionX - cos(angle)*second->radius;
	}
	if (tempY < 0)
	{
		temp1Y = collisionPositionY - sin(angle)*first->radius;
		temp2Y = collisionPositionY + sin(angle)*second->radius;
	}
	else
	{
		temp1Y = collisionPositionY + sin(angle)*first->radius;
		temp2Y = collisionPositionY - sin(angle)*second->radius;
	}

	first->SetPosition(sf::Vector2f(temp1X, temp1Y));
	second->SetPosition(sf::Vector2f(temp2X, temp2Y));

	float firstNormalSpeedBefore  = cos(angle) * first->GetNextSpeed().x  + sin(angle) * first->GetNextSpeed().y;
	float secondNormalSpeedBefore = cos(angle) * second->GetNextSpeed().x + sin(angle) * second->GetNextSpeed().y;

	float restitutionAverage = (first->restitutionMultiplier + second->restitutionMultiplier) * 0.5f;
	float firstNormalSpeedAfter = ((first->mass - restitutionAverage * second->mass) / (first->mass + second->mass)) * firstNormalSpeedBefore
		+ (((1 + restitutionAverage) * second->mass) / (first->mass + second->mass)) * secondNormalSpeedBefore;

	float secondNormalSpeedAfter = (((1 + restitutionAverage) * first->mass) / (first->mass + second->mass)) * firstNormalSpeedBefore
		+ ((second->mass - restitutionAverage * first->mass) / (first->mass + second->mass)) * secondNormalSpeedBefore;

	//float firstNormalSpeedAfter = (first->restitutionMultiplier * second->mass * (secondNormalSpeedBefore - firstNormalSpeedBefore)
	//	+ first->mass * firstNormalSpeedBefore + second->mass*secondNormalSpeedBefore) / (first->mass + second->mass);

	//float secondNormalSpeedAfter = (second->restitutionMultiplier * first->mass * (firstNormalSpeedBefore - secondNormalSpeedBefore)
	//	+ first->mass * firstNormalSpeedBefore + second->mass*secondNormalSpeedBefore) / (first->mass + second->mass);


	float firstTangentSpeed  = cos(angle)*first->GetNextSpeed().y  - sin(angle)*first->GetNextSpeed().x;
	float secondTangentSpeed = cos(angle)*second->GetNextSpeed().y - sin(angle)*second->GetNextSpeed().x;

	float firstFinalX = firstNormalSpeedAfter * cos(angle) - firstTangentSpeed * sin(angle);
	float firstFinalY = firstNormalSpeedAfter * sin(angle) + firstTangentSpeed * cos(angle);


	float secondFinalX = secondNormalSpeedAfter * cos(angle) - secondTangentSpeed * sin(angle);
	float secondFinalY = secondNormalSpeedAfter * sin(angle) + secondTangentSpeed * cos(angle);

	/*float firstFinalX = sin(angle)*(firstNormalSpeedAfter + firstTangentSpeed);
	float firstFinalY = cos(angle)*(firstNormalSpeedAfter + firstTangentSpeed);

	float secondFinalX = cos(angle)*(secondNormalSpeedAfter + secondTangentSpeed);
	float secondFinalY = sin(angle)*(secondNormalSpeedAfter + secondTangentSpeed);*/

	first->SetSpeed(sf::Vector2f(firstFinalX, firstFinalY));
	second->SetSpeed(sf::Vector2f(secondFinalX, secondFinalY));

	first->SetNextPosition(sf::Vector2f(UpdatePosition(first->GetPosition().x, first->GetSpeed().x, 0), UpdatePosition(first->GetPosition().y, first->GetSpeed().y, gravityAcceleration)));
	first->SetNextSpeed(sf::Vector2f(UpdateSpeed(first->GetSpeed().x, 0), UpdateSpeed(first->GetSpeed().y, gravityAcceleration)));
	
	second->SetNextPosition(sf::Vector2f(UpdatePosition(second->GetPosition().x, second->GetSpeed().x, 0), UpdatePosition(second->GetPosition().y, second->GetSpeed().y, gravityAcceleration)));
	second->SetNextSpeed(sf::Vector2f(UpdateSpeed(second->GetSpeed().x, 0), UpdateSpeed(second->GetSpeed().y, gravityAcceleration)));

}