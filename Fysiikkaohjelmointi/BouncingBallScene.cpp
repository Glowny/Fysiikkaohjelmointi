#include "BouncingBallScene.h"


BouncingBallScene::BouncingBallScene(sf::RenderWindow* window) :Scene(window)
{
	physicsLoopTime = 0;
	valueBoxLoopTime = 0;

	texture.loadFromFile("pallo.png");
	texture.setSmooth(true);
	ball = BouncingBallEntity(1.0f, 0.6f, sf::Sprite(texture));
	ball.SetPosition(sf::Vector2f(0, -600));
	demoBox->drawVector.push_back(ball.GetSprite());
	tempFloatTestMasterfulBoolpaskafix = 0;
	valueBox->AddVarValue(&ball.GetPositionPointer()->x, "Position X");
	valueBox->AddVarValue(&ball.GetPositionPointer()->y, "Position Y");
	valueBox->AddVarValue(&ball.GetSpeedPointer()->x, "Speed X");
	valueBox->AddVarValue(&ball.GetSpeedPointer()->y, "Speed Y");
}

BouncingBallScene::~BouncingBallScene()
{
}

void BouncingBallScene::Update(float dt)
{
	UpdatePhysics(dt);
	UpdateValueBox(dt);
}

void BouncingBallScene::UpdatePhysics(float dt)
{
	physicsLoopTime += dt;
	while (physicsLoopTime >= Physics::deltaTime)
	{
		Physics::GravityFunc(&ball);

		physicsLoopTime -= Physics::deltaTime;

		if (ball.GetNextPosition().y > 0)
		{
			ball.SetPosition(sf::Vector2f(ball.GetPosition().x, 0));
			ball.SetSpeed(sf::Vector2f(ball.GetSpeed().x, Physics::InelasticCollision(ball.GetSpeed().y, 0.5)));
		}
	}
}

void BouncingBallScene::UpdateValueBox(float dt)
{
	valueBoxLoopTime += dt;
	if (valueBoxLoopTime >= 0.1f)
	{
		valueBoxLoopTime -= 0.1f;
		valueBox->Update();
	}
}