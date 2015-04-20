#pragma once
#include "TextBox.h"
#include "ValueBox.h"
#include "DemoBox.h"
#include "Physics.h"

class Scene
{
public:
	Scene(sf::Window* window);
	~Scene();
	void Draw();
	virtual void Update();
protected:
//	vector<Object>
	TextBox* textBox;
	ValueBox* valueBox;
	DemoBox* demoBox;
};

