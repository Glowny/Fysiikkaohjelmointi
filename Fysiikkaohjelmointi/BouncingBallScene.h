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
	void UpdateValueBox(float dt);
	bool CheckCollision(BouncingBallEntity* first, BouncingBallEntity* second);

	sf::Texture texture;
	BouncingBallEntity ball1;
	BouncingBallEntity ball2;

	float tempFloatTestMasterfulBoolpaskafix;

	float valueBoxLoopTime;
	float physicsLoopTime;
};

