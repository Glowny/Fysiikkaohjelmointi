#include "BouncingBallScene.h"


BouncingBallScene::BouncingBallScene(sf::RenderWindow* window) :Scene(window)
{
	physicsLoopTime = 0;
	valueBoxLoopTime = 0;

	texture.loadFromFile("pallo.png");
	texture.setSmooth(true);
	ball1 = BouncingBallEntity(1.0f, 0.9f, sf::Sprite(texture));
	ball1.SetPosition(sf::Vector2f(-250, -600));
	demoBox->drawVector.push_back(ball1.GetSprite());
	
	valueBox->AddVarValue(&ball1.GetPositionPointer()->x, "1 Position X");
	valueBox->AddVarValue(&ball1.GetPositionPointer()->y, "1 Position Y");
	valueBox->AddVarValue(&ball1.GetSpeedPointer()->x, "1 Speed X");
	valueBox->AddVarValue(&ball1.GetSpeedPointer()->y, "1 Speed Y");

	ball2 = BouncingBallEntity(2.0f, 0.5f, sf::Sprite(texture));
	ball2.SetPosition(sf::Vector2f(250, -600));
	demoBox->drawVector.push_back(ball2.GetSprite());

	ball2.SetSpeed(sf::Vector2f(-150, 0));

	valueBox->AddVarValue(&ball2.GetPositionPointer()->x, "2 Position X");
	valueBox->AddVarValue(&ball2.GetPositionPointer()->y, "2 Position Y");
	valueBox->AddVarValue(&ball2.GetSpeedPointer()->x, "2 Speed X");
	valueBox->AddVarValue(&ball2.GetSpeedPointer()->y, "2 Speed Y");

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
		physicsLoopTime -= Physics::deltaTime;
		
		Physics::GravityFunc(&ball1);
		Physics::GravityFunc(&ball2);

		if (ball1.GetNextPosition().y - ball1.radius > 0)
		{
			ball1.SetPosition(sf::Vector2f(ball1.GetPosition().x, ball1.radius));
			ball1.SetSpeed(sf::Vector2f(ball1.GetSpeed().x, Physics::InelasticCollision(ball1.GetSpeed().y, ball1.restitutionMultiplier)));
		}
		if (ball2.GetNextPosition().y - ball2.radius > 0)
		{
			ball2.SetPosition(sf::Vector2f(ball2.GetPosition().x, ball2.radius));
			ball2.SetSpeed(sf::Vector2f(ball2.GetSpeed().x, Physics::InelasticCollision(ball2.GetSpeed().y, ball2.restitutionMultiplier)));
		}

		if (ball1.GetNextPosition().x - ball1.radius < -390)
		{
			ball1.SetPosition(sf::Vector2f(-390+ball1.radius, ball1.GetPosition().y));
			ball1.SetSpeed(sf::Vector2f(Physics::InelasticCollision(ball1.GetSpeed().x, ball1.restitutionMultiplier), ball1.GetSpeed().y));
		}
		if (ball2.GetNextPosition().x + ball2.radius > 390)
		{
			ball1.SetPosition(sf::Vector2f(390-ball1.radius, ball1.GetPosition().y));
			ball1.SetSpeed(sf::Vector2f(Physics::InelasticCollision(ball1.GetSpeed().x, ball1.restitutionMultiplier), ball1.GetSpeed().y));
		}

		if (ball2.GetNextPosition().x - ball2.radius < -390)
		{
			ball2.SetPosition(sf::Vector2f(-390 + ball2.radius, ball2.GetPosition().y));
			ball2.SetSpeed(sf::Vector2f(Physics::InelasticCollision(ball2.GetSpeed().x, ball2.restitutionMultiplier), ball2.GetSpeed().y));
		}
		if (ball2.GetNextPosition().x + ball2.radius > 390)
		{
			ball2.SetPosition(sf::Vector2f(390 - ball2.radius, ball2.GetPosition().y));
			ball2.SetSpeed(sf::Vector2f(Physics::InelasticCollision(ball2.GetSpeed().x, ball2.restitutionMultiplier), ball2.GetSpeed().y));
		}

		if (CheckCollision(&ball1, &ball2))
		{
			Physics::InelasticObjectCollision(&ball1, &ball2);
		}
	}
}

void BouncingBallScene::UpdateValueBox(float dt)
{
	valueBoxLoopTime += dt;
	if (valueBoxLoopTime >= 0.2f)
	{
		valueBoxLoopTime -= 0.2f;
		valueBox->Update();
	}
}

bool BouncingBallScene::CheckCollision(BouncingBallEntity* first, BouncingBallEntity* second)
{
	float tempX = first->GetNextPosition().x - second->GetNextPosition().x;
	float tempY = first->GetNextPosition().y - second->GetNextPosition().y;
	float tempDistance = sqrt(tempX * tempX + tempY * tempY);
	
	if (tempDistance <= first->radius + second->radius)
		return true;
	else
		return false;
}