#pragma once
#include "Box.h"
class TextBox:public Box
{
public:
	TextBox(sf::RenderWindow* window, sf::FloatRect rectangle, std::string filename);
	~TextBox();
	void Draw();
private:
	sf::Texture physicText;
	sf::Sprite physicTextSprite;
};

