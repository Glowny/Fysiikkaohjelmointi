#pragma once
#include "Box.h"
class TextBox:public Box
{
public:
	TextBox(sf::RenderWindow* window, sf::FloatRect rectangle);
	~TextBox();
};

