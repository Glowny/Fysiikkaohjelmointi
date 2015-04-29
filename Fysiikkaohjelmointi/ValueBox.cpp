#include "ValueBox.h"


ValueBox::ValueBox(sf::RenderWindow* window, sf::FloatRect rectangle) : Box(window, rectangle)
{
	
}


ValueBox::~ValueBox()
{

}

void ValueBox::AddVarValue(float* valuePointer, std::string name)
{
	int apumx = varValueVector.size() % 2;
	int apumy = (varValueVector.size() - apumx) / 2;
	varValueVector.push_back(VarValue(valuePointer, name, sf::Vector2f(205 * apumx, 55 * apumy)));
}

void ValueBox::Update()
{
	for (int i = 0; i < varValueVector.size(); i++)
	{
		sf::FloatRect temp = MoveToLocalCoordinates(varValueVector[i].inputBox.getGlobalBounds());
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && temp.contains(MouseCoordinateWrapper::GetMousePosition()))
		{
			if (activeBox == nullptr)
			{
				activeBox = &varValueVector[i];
				activeBox->inputBox.setFillColor(sf::Color::Blue);
			}
			else if (activeBox != nullptr && activeBox != &varValueVector[i])
			{
				activeBox->AbortThread();
				activeBox->inputBox.setFillColor(sf::Color::Green);
				activeBox = nullptr;
			}
		}

		varValueVector[i].Update();
	}

	if (activeBox != nullptr)
	{
		activeBox->SetValue();
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

// private

sf::FloatRect ValueBox::MoveToLocalCoordinates(sf::FloatRect rect)
{
	sf::FloatRect temp = rect;
	temp.left = rect.left + 499.0f;
	temp.top = rect.top + 787.0f;

	return temp;
}