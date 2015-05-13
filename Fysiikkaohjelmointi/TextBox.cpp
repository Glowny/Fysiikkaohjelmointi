#include "TextBox.h"


TextBox::TextBox(sf::RenderWindow* window, sf::FloatRect rectangle, std::string filename) : Box(window, rectangle)
{
	physicText.loadFromFile(filename);
	physicTextSprite.setTexture(physicText);
	physicTextSprite.setPosition(rectangle.left+5, rectangle.top+5);

}

TextBox::~TextBox()
{
}

void TextBox::Draw()
{
	window->draw(physicTextSprite);
}
