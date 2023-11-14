#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Exception.h"

#define NUMBER_OF_DIALOGUES 4

using namespace std;
using namespace sf;


class AbilityChoice
{
public:
	AbilityChoice();
	void draw(RenderWindow& window);
	
	// Methods to handle user navigation in the menu
	void moveUp();
	void moveDown();

	// Method to handle button press and return the selected choice
	int buttonPress();

private:
	int choice; // Current choice selected by the user
	Font font; // Font for rendering text
	Text text[NUMBER_OF_DIALOGUES]; // Array of Text objects for displaying dialogues
};

