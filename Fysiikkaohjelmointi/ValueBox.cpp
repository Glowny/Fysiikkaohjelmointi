#include "ValueBox.h"
#include <stdexcept>

ValueBox::ValueBox(sf::RenderWindow* window, sf::FloatRect rectangle) : Box(window, rectangle)
{
	
}


ValueBox::~ValueBox()
{

}

void ValueBox::InitializeInput(std::string* stringPointer)
{
	inputString = stringPointer;
}

void ValueBox::AddVarValue(float* valuePointer, std::string name)
{
	int apumx = varValueVector.size() % 4;
	int apumy = (varValueVector.size() - apumx) / 3;
	varValueVector.push_back(VarValue(valuePointer, name, sf::Vector2f(10 + 192 * apumx, 10 + 56 * apumy)));
}
void ValueBox::AddVarValue(float* valuePointer, float* setValuePointer, std::string name)
{
	int apumx = varValueVector.size() % 4;
	int apumy = (varValueVector.size() - apumx) / 3;

	varValueVector.push_back(VarValue(valuePointer, setValuePointer, name, sf::Vector2f(10 + 192 * apumx, 10 + 56 * apumy)));
}

void ValueBox::Update()
{
	for (int i = 0; i < varValueVector.size(); i++)
	{
		varValueVector[i].Update();
	}

	if (activeBox != nullptr)
	{
		activeBox->SetValue(inputString);
	}
}

void ValueBox::Draw()
{
	for (int i = 0; i < varValueVector.size(); i++)
	{
			window->draw(varValueVector[i].inputBox, state);
			window->draw(varValueVector[i].valueText, state);
			window->draw(varValueVector[i].valueName, state);
	}
}

void ValueBox::CheckMousePress()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && activeBox != nullptr)
		ReleaseActiveBox();
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		return;

	bool pressedNothing = true;

	for (int i = 0; i < varValueVector.size(); i++)
	{
		sf::FloatRect temp = MoveToLocalCoordinates(varValueVector[i].inputBox.getGlobalBounds());

		if(temp.contains(MouseCoordinateWrapper::GetMousePosition()))
		{
			pressedNothing = false;
			if (activeBox == nullptr)
			{
				activeBox = &varValueVector[i];
				activeBox->inputBox.setFillColor(sf::Color(150, 150, 150));
			}
			else if (activeBox != nullptr && activeBox != &varValueVector[i])
			{
				ReleaseActiveBox();
			}
		}
	}
	if (activeBox != nullptr && pressedNothing)
	{
		ReleaseActiveBox();
	}
}

// private

sf::FloatRect ValueBox::MoveToLocalCoordinates(sf::FloatRect rect)
{
	sf::FloatRect temp = rect;
	temp.left = rect.left + 499.0f;
	temp.top = rect.top + 787.0f;

	return temp;
}

void ValueBox::ReleaseActiveBox()
{
	SetVarValue();
	activeBox->inputBox.setFillColor(sf::Color(200, 200, 200));
	activeBox = nullptr;
	inputString->clear();
}

void ValueBox::SetVarValue()
{
	if (activeBox->setValuePointer == nullptr)
		return;
	float newValue;
	try
	{
		newValue = std::stof(*inputString);
	}
	catch (std::invalid_argument& e)
	{
		return;
	}

	*activeBox->setValuePointer = newValue;	
	*activeBox->valuePointer = newValue;
}