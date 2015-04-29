#pragma once
#include "Box.h"
#include "VarValue.h"
#include "MouseCoordinateWrapper.h"
#include <thread>
class ValueBox:public Box
{
public:
	ValueBox(sf::RenderWindow* window, sf::FloatRect rectangle);
	~ValueBox();
	void AddVarValue(float* valuePointer, std::string name);
	void Update();
	void Draw();
private:
	sf::FloatRect MoveToLocalCoordinates(sf::FloatRect rect);
	std::vector<VarValue> varValueVector;
	VarValue* activeBox;
};

