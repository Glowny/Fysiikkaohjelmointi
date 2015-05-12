#pragma once
#include "TextBox.h"
#include "ValueBox.h"
#include "DemoBox.h"
#include "Physics.h"
#include "SFML\Graphics.hpp"


class Scene
{
public:
	Scene(sf::RenderWindow* window);
	~Scene();
	void TogglePausePhysics();
	void TogglePausePhysics(bool pause);
	void Draw();
	virtual void Update();
	void SetInputString(std::string* inputString);	// Asetetaan inputstring valueboxille, koska event-looppi on mainissa.
													// T�h�n saattaa olla olemassa n�timpi ratkaisu jos event-looppi saatas tehty� toisen kerran / teht�isiin t�nne.
protected:

	sf::Window* window;
	virtual void UpdatePhysics(){};
	bool pause;
//	vector<Object>
	TextBox* textBox;
	ValueBox* valueBox;
	DemoBox* demoBox;
};

