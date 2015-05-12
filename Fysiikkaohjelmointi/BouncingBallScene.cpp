#include "BouncingBallScene.h"


BouncingBallScene::BouncingBallScene(sf::RenderWindow* window) :Scene(window)
{
	physicsLoopTime = 0;
	valueBoxLoopTime = 0;

	texture.loadFromFile("pallo.png");
	texture.setSmooth(true);

	texture2.loadFromFile("Ball-8.png");
	texture.setSmooth(true);

	BouncingBallEntity* ball1 = new BouncingBallEntity(0.01f, 1.0f, sf::Sprite(texture));
	ball1->SetPosition(sf::Vector2f(20, -300));
	ball1->GetSprite()->setColor(sf::Color::Red);
	demoBox->drawVector.push_back(ball1->GetSprite());
	valueBox->AddVarValue(&ball1->GetCurrentPositionPointer()->x, &ball1->GetNextPositionPointer()->x, "1 Position X");
	valueBox->AddVarValue(&ball1->GetCurrentPositionPointer()->y, &ball1->GetNextPositionPointer()->y, "1 Position Y");
	valueBox->AddVarValue(&ball1->GetCurrentSpeedPointer()->x, &ball1->GetNextSpeedPointer()->x, "1 Speed X");
	valueBox->AddVarValue(&ball1->GetCurrentSpeedPointer()->y, &ball1->GetNextSpeedPointer()->y,"1 Speed Y");
	ballVector.push_back(ball1);
	
	BouncingBallEntity* ball2 = new BouncingBallEntity(5000.0f, 0.01f, sf::Sprite(texture2)); 
	ball2->GetSprite()->setColor(sf::Color::Blue);
	ball2->SetPosition(sf::Vector2f(0, 0));
	
	demoBox->drawVector.push_back(ball2->GetSprite());
	valueBox->AddVarValue(&ball2->GetCurrentPositionPointer()->x, &ball2->GetNextPositionPointer()->x, "2 Position X");
	valueBox->AddVarValue(&ball2->GetCurrentPositionPointer()->y, &ball2->GetNextPositionPointer()->y, "2 Position Y");
	valueBox->AddVarValue(&ball2->GetCurrentSpeedPointer()->x, &ball2->GetNextSpeedPointer()->x, "2 Speed X");
	valueBox->AddVarValue(&ball2->GetCurrentSpeedPointer()->y, &ball2->GetNextSpeedPointer()->y, "2 Speed Y");
	ballVector.push_back(ball2);

	//BouncingBallEntity* ball3 = new BouncingBallEntity(10.0f, 1.0f, sf::Sprite(texture));
	//ball3->GetSprite()->setColor(sf::Color::Green);
	//ball3->SetPosition(sf::Vector2f(200, -300));
	//demoBox->drawVector.push_back(ball3->GetSprite());
	//valueBox->AddVarValue(&ball3->GetPositionPointer()->x, "3 Position X");
	//valueBox->AddVarValue(&ball3->GetPositionPointer()->y, "3 Position Y");
	//valueBox->AddVarValue(&ball3->GetSpeedPointer()->x, "3 Speed X");
	//valueBox->AddVarValue(&ball3->GetSpeedPointer()->y, "3 Speed Y");
	//ballVector.push_back(ball3);

	//ball1->SetSpeed(sf::Vector2f(0, 50));
	//ball2->SetSpeed(sf::Vector2f(0, 0));
	//ball3->SetSpeed(sf::Vector2f(100, 10));

	for (int i = 0; i < 10; i++)
	{
		BouncingBallEntity* newBall = new BouncingBallEntity(i*20.0f, 0.9, sf::Sprite(texture));
		newBall->SetPosition(sf::Vector2f(-350 + i*64, -350));
		newBall->GetSprite()->setColor(sf::Color(150 + i * 10, i * 20, i * 25));
		demoBox->drawVector.push_back(newBall->GetSprite());
		ballVector.push_back(newBall);
	}

}

BouncingBallScene::~BouncingBallScene()
{
	for (int i = 0; i < ballVector.size(); i++)
		delete ballVector[i];
}

void BouncingBallScene::Update(float dt)
{
	if (!pause)
	UpdatePhysics(dt);

	UpdateValueBox(dt);
}

void BouncingBallScene::UpdatePhysics(float dt)
{
	physicsLoopTime += dt;
	while (physicsLoopTime >= Physics::deltaTime)
	{
		physicsLoopTime -= Physics::deltaTime;
		
		for (int i = 0; i < ballVector.size(); i++)
		{
			Physics::GravityFunc(ballVector[i]);



			if (ballVector[i]->GetNextPosition().y + ballVector[i]->radius > 0)
			{
				ballVector[i]->SetPosition(sf::Vector2f(ballVector[i]->GetPosition().x, -ballVector[i]->radius));
				ballVector[i]->SetSpeed(sf::Vector2f(ballVector[i]->GetSpeed().x, Physics::InelasticCollision(ballVector[i]->GetSpeed().y, ballVector[i]->restitutionMultiplier)));
			}

			if (ballVector[i]->GetNextPosition().y - ballVector[i]->radius < -777)
			{
				ballVector[i]->SetPosition(sf::Vector2f(ballVector[i]->GetPosition().x, -777 + ballVector[i]->radius));
				ballVector[i]->SetSpeed(sf::Vector2f(ballVector[i]->GetSpeed().x, Physics::InelasticCollision(ballVector[i]->GetSpeed().y, ballVector[i]->restitutionMultiplier)));
			}
		
			if (ballVector[i]->GetNextPosition().x - ballVector[i]->radius < -390)
			{
				ballVector[i]->SetPosition(sf::Vector2f(-390 + ballVector[i]->radius, ballVector[i]->GetPosition().y));
				ballVector[i]->SetSpeed(sf::Vector2f(Physics::InelasticCollision(ballVector[i]->GetSpeed().x, ballVector[i]->restitutionMultiplier), ballVector[i]->GetSpeed().y));
			}
			if (ballVector[i]->GetNextPosition().x + ballVector[i]->radius > 390)
			{
				ballVector[i]->SetPosition(sf::Vector2f(390 - ballVector[i]->radius, ballVector[i]->GetPosition().y));
				ballVector[i]->SetSpeed(sf::Vector2f(Physics::InelasticCollision(ballVector[i]->GetSpeed().x, ballVector[i]->restitutionMultiplier), ballVector[i]->GetSpeed().y));
			}

			for (int j = i+1; j < ballVector.size(); j++)
			{
				if (CheckCollision(ballVector[i], ballVector[j]))
				{
					Physics::InelasticObjectCollision(ballVector[i], ballVector[j]);
				}
			}
			
		}
	}
}

void BouncingBallScene::UpdateValueBox(float dt)
{
	valueBox->CheckMousePress();
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