#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/System.hpp>
#include "BouncingBallScene.h"
#include "IncludeHeader.h"
#include "MouseCoordinateWrapper.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 1024), "SFML works!");
	sf::Texture bg;
	bg.loadFromFile("kauniitdimensiot.png");
	sf::Sprite sprite(bg);
	MouseCoordinateWrapper::Initialize(&window);

	BouncingBallScene scene(&window);
	std::string inputString;
	scene.SetInputString(&inputString);
	sf::Clock clock;
	sf::Time time;
	
	float dt;
	float fpsUpdate = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					inputString += static_cast<char>(event.text.unicode);
				}
			}
		}
		time = clock.restart();
		dt = time.asSeconds();

		fpsUpdate += dt;
		if (fpsUpdate >= 0.3)
		{
			window.setTitle(std::to_string(1/dt));
			fpsUpdate = 0;
		}

		scene.Update(dt);
		window.clear();
		window.draw(sprite);
		scene.Draw();
		window.display();
	}

	return 0;
}
