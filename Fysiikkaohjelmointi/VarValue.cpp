#include "VarValue.h"


VarValue::VarValue(float* valuePointer, std::string valueName, sf::Vector2f pos)
{
	position = pos;
	arialFont.loadFromFile("arial.ttf");
	this->valuePointer = valuePointer;
	this->setValuePointer = valuePointer;
	this->valueName.setFont(arialFont);
	this->valueName.setColor(sf::Color::Black);
	this->valueName.setCharacterSize(16);
	this->valueName.setStyle(sf::Text::Regular);

	valueText = this->valueName;

	this->valueName.setString(valueName);
	this->valueText.setString(std::to_string(*valuePointer));
	valueText.setPosition(0, 18);
	
	inputBox.setFillColor(sf::Color(200, 200, 200));
	inputBox.setSize(sf::Vector2f(187, 51.0f));

	inputBox.setOutlineThickness(1);
	inputBox.setOutlineColor(sf::Color::Black);

	this->valueName.setPosition(position);
	this->valueText.setPosition(position.x, position.y +18);
	inputBox.setPosition(position);
}
VarValue::VarValue(float* valuePointer, float* setValuePointer, std::string valueName, sf::Vector2f pos)
{
	position = pos;
	arialFont.loadFromFile("arial.ttf");
	this->valuePointer = valuePointer;
	this->setValuePointer = setValuePointer;
	this->valueName.setFont(arialFont);
	this->valueName.setColor(sf::Color::Black);
	this->valueName.setCharacterSize(16);
	this->valueName.setStyle(sf::Text::Regular);

	valueText = this->valueName;

	this->valueName.setString(valueName);
	this->valueText.setString(std::to_string(*valuePointer));
	valueText.setPosition(0, 18);

	inputBox.setFillColor(sf::Color(200, 200, 200));
	inputBox.setSize(sf::Vector2f(187, 51.0f));

	inputBox.setOutlineThickness(1);
	inputBox.setOutlineColor(sf::Color::Black);

	this->valueName.setPosition(position);
	this->valueText.setPosition(position.x, position.y + 18);
	inputBox.setPosition(position);
}
VarValue::~VarValue()
{
}

void VarValue::Update()
{
	valueText.setString(std::to_string(*valuePointer));
}

void VarValue::SetValue(std::string* inputString)
{
	valueText.setString(*inputString);
}

