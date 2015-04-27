#pragma once
#include "TextBox.h"
#include "ValueBox.h"
#include "DemoBox.h"
#include "Physics.h"
#include "SFML\Graphics.hpp"


class Scene
{
public:
	Scene(sf::RenderWindow* window);
	~Scene();
	void Draw();
	virtual void Update();
protected:
	virtual void UpdatePhysics(){};
//	vector<Object>
	TextBox* textBox;
	ValueBox* valueBox;
	DemoBox* demoBox;
};

