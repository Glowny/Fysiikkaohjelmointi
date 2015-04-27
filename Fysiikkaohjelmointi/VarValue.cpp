#include "VarValue.h"


VarValue::VarValue(float* valuePointer, std::string valueName)
{
	arialFont.loadFromFile("arial.ttf");
	this->valuePointer = valuePointer;
	this->valueName.setFont(arialFont);
	this->valueName.setColor(sf::Color::Magenta);
	this->valueName.setCharacterSize(16);
	this->valueName.setStyle(sf::Text::Regular);

	valueText = this->valueName;

	this->valueName.setString(valueName);
	this->valueText.setString(std::to_string(*valuePointer));
	valueText.setPosition(0, 18);
	
	inputBox.setFillColor(sf::Color::Green);
	inputBox.setSize(sf::Vector2f(200.0f, 50.0f));
}

VarValue::~VarValue()
{
}


