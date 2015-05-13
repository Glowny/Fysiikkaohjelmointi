#include "Scene.h"



Scene::Scene(sf::RenderWindow* window)
{
	this->window = window;
	pause = false;
	textBox = new TextBox(window, sf::FloatRect(0.0f, 0.0f, 489.0f, 1024.0f),"physicText.png");
	valueBox = new ValueBox(window, sf::FloatRect(499.0f, 787.0f, 1280.0f, 1024.0f));
	demoBox = new DemoBox(window, sf::FloatRect(505.0f, 0.0f, 770.0f, 770.0f));
}



Scene::~Scene()
{
	delete textBox;
	delete valueBox;
	delete demoBox;
}
void Scene::SetInputString(std::string* inputString)
{
	if (valueBox != nullptr)
	{
		valueBox->InitializeInput(inputString);
	}
}
void Scene::TogglePausePhysics(bool pause)
{
	this->pause = pause;
}

void Scene::TogglePausePhysics()
{
	pause = !pause;
}

void Scene::Draw()
{
	textBox->Draw();
	valueBox->Draw();
	demoBox->Draw();
}

void Scene::Update()
{
	valueBox->Update();	
	demoBox->Update();
}