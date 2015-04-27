#pragma once
#include <string>
#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
#include "IncludeHeader.h"

class VarValue
{
public:
	VarValue(float* valuePointer, std::string valueName);
	~VarValue();
	void Update();
	float* valuePointer;
	sf::Text valueName;
	sf::Text valueText;
	sf::RectangleShape inputBox;
};

