#pragma once
#include "Scene.h"
#include "BouncingBallEntity.h"
class BouncingBallScene:public Scene
{
public:
	BouncingBallScene(sf::RenderWindow* window);
	~BouncingBallScene();
	void Update(float dt);
private:
	void UpdatePhysics(float dt);

	sf::Texture texture;
	BouncingBallEntity ball;

	float tempFloatTestMasterfulBoolpaskafix;
	float physicsLoopTime;
};

