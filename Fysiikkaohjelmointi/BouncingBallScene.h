#pragma once
#include "Scene.h"
#include "BouncingBallEntity.h"
#include <vector>
class BouncingBallScene:public Scene
{
public:
	BouncingBallScene(sf::RenderWindow* window);
	~BouncingBallScene();
	void Update(float dt);
	void AddBall();
private:
	std::vector<BouncingBallEntity*> ballVector;
	void UpdatePhysics(float dt);
	void UpdateValueBox(float dt);
	bool CheckCollision(BouncingBallEntity* first, BouncingBallEntity* second);

	sf::Texture texture;
	sf::Texture texture2;
	
	float tempFloatTestMasterfulBoolpaskafix;

	float valueBoxLoopTime;
	float physicsLoopTime;
};

