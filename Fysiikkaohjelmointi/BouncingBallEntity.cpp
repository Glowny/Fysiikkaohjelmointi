#include "BouncingBallEntity.h"


BouncingBallEntity::BouncingBallEntity(float mass, float restitutionMultiplier,sf::Sprite sprite)
{
	this->mass = mass;
	this->restitutionMultiplier = restitutionMultiplier;
	this->sprite = sf::Sprite(sprite);
	this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	radius = sprite.getLocalBounds().width / 2;
}


BouncingBallEntity::~BouncingBallEntity()
{
}

float* BouncingBallEntity::GetRestitutionPointer()
{
	return &restitutionMultiplier;
}

float* BouncingBallEntity::GetMassPointer()
{
	return &mass;
}