#pragma once
#include "Box.h"
class ValueBox:public Box
{
public:
	ValueBox(sf::RenderWindow* window, sf::FloatRect rectangle);
	~ValueBox();
};

