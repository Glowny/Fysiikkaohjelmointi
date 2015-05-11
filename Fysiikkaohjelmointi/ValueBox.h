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
	void InitializeInput(std::string* stringPointer);	// Event-loopista täytyy hakea string, joten mainista tähän laitetaan pointteri osoittamaan.
	void AddVarValue(float* valuePointer, std::string name);
	void Update();
	void Draw();
	void CheckMousePress();

private:
	sf::FloatRect MoveToLocalCoordinates(sf::FloatRect rect);
	void ReleaseActiveBox();
	void SetVarValue();	// Asettaa fysiikoille uuden arvon.
	std::string* inputString;
	std::vector<VarValue> varValueVector;
	VarValue* activeBox;
	
};

