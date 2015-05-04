#pragma once
#include "BouncingBallEntity.h"
#include "SFML\System.hpp"

class Physics
{
public:
	const static float gravityAcceleration;
	const static float deltaTime;
	static void GravityFunc(Entity* entity);
	
	static float UpdateSpeed(float speed, float acceleration);
	static float UpdatePosition(float position, float speed, float acceleration);

	static float InelasticCollision(float speed, float restitution);
	static void InelasticObjectCollision(BouncingBallEntity* first, BouncingBallEntity* second);
};

