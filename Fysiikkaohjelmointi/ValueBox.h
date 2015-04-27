#pragma once
#include "Box.h"
#include "VarValue.h"
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
	std::vector<VarValue> varValueVector;
};

