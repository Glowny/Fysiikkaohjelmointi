#include "Scene.h"


Scene::Scene(sf::Window* window)
{
	textBox = new TextBox(window);
	valueBox = new ValueBox(window);
	demoBox = new DemoBox(window);
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