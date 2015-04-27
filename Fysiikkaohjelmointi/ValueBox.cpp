#include "ValueBox.h"


ValueBox::ValueBox(sf::RenderWindow* window, sf::FloatRect rectangle) : Box(window, rectangle)
{
	
}


ValueBox::~ValueBox()
{

}

void ValueBox::AddVarValue(float* valuePointer, std::string name)
{

	varValueVector.push_back(VarValue(valuePointer, name));
}

void ValueBox::Update()
{

}

void ValueBox::Draw()
{
	sf::RenderStates tempState = state;
	for (int i = 0; i < varValueVector.size(); i++)
	{
			tempState.transform.translate(0, 80*i);

			window->draw(varValueVector[i].inputBox, tempState);
			window->draw(varValueVector[i].valueText, tempState);
			window->draw(varValueVector[i].valueName, tempState);
	}
}