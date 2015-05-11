#include "Scene.h"



Scene::Scene(sf::RenderWindow* window)
{
	textBox = new TextBox(window, sf::FloatRect(0.0f, 0.0f, 489.0f, 1024.0f));
	valueBox = new ValueBox(window, sf::FloatRect(499.0f, 787.0f, 1280.0f, 1024.0f));
	demoBox = new DemoBox(window, sf::FloatRect(499.0f, 0.0f, 1280.0f, 777.0f));
}

void Scene::SetInputString(std::string* inputString)
{
	if (valueBox != nullptr)
	{
		valueBox->InitializeInput(inputString);
	}
}

Scene::~Scene()
{
	delete textBox;
	delete valueBox;
	delete demoBox;
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