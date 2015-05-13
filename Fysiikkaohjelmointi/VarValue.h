#pragma once
#include <string>
#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
#include "IncludeHeader.h"

class VarValue
{
public:
	VarValue(float* valuePointer, std::string valueName, sf::Vector2f pos); // For functions that need only one pointer (shared getter/setter) 
	VarValue(float* valuePointer,float* setValuePointer, std::string valueName, sf::Vector2f pos);	// For functions that need two pointers (getter and setter). 
	~VarValue();
	void Update();
	void SetValue(std::string* inputString);
	void AbortThread();

	float* valuePointer;
	float* setValuePointer;
	sf::Text valueName;
	sf::Text valueText;
	sf::RectangleShape inputBox;
	sf::Vector2f position;
};

