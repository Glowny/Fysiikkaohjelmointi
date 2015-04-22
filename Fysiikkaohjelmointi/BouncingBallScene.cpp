#include "BouncingBallScene.h"


BouncingBallScene::BouncingBallScene(sf::RenderWindow* window) :Scene(window)
{
	texture.loadFromFile("pallo.png");
	texture.setSmooth(true);
	ball = BouncingBallEntity(1.0f, 0.6f, sf::Sprite(texture));
	ball.SetPosition(sf::Vector2f(0, -600));
	physicsLoopTime = 0;
	demoBox->drawVector.push_back(ball.GetSprite());
}

BouncingBallScene::~BouncingBallScene()
{
}

void BouncingBallScene::Update(float dt)
{
	UpdatePhysics(dt);
	

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
			ball.SetSpeed(sf::Vector2f(ball.GetSpeed().x, Physics::InelasticCollision(ball.GetSpeed().y, 0.9)));
		}
	}
}