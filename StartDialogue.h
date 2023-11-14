#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Exception.h"


using namespace std;
using namespace sf;


class StartDialogue
{
public:
	StartDialogue();
	void draw(RenderWindow& window);
	void text_2();
private:
	Font font;
	Text textStart;
};

class DialogueCloud 
{
public:
	DialogueCloud();
	void draw(RenderWindow& window);
	

private:
	Texture texture;
	Sprite cloud;
};