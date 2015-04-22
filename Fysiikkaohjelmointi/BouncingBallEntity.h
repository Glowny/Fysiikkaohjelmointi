#pragma once
#include "Entity.h"

class BouncingBallEntity:public Entity
{
public:
	BouncingBallEntity(){}
	BouncingBallEntity(float mass, float restitutionMultiplier, sf::Sprite sprite);
	~BouncingBallEntity();
	float mass;
	float restitutionMultiplier;
};

