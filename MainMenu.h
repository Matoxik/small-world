#pragma once
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Exception.h"

using namespace std;
using namespace sf;


#define MAX_POSITION 3 // Maximum number of items to select in the menu

class MainMenu
{
public:
	MainMenu(float width, float height);

	void draw(RenderWindow& window);
	// Methods to navigate up and down in the menu
	void moveUp();
	void moveDown();

	// Method to get the selected option in the main menu
	int buttonPressMainMenu()
	{
		return ChoiceMainMenu;
	}
	~MainMenu();

private:
	int ChoiceMainMenu;  // Variable to store the selected menu option
	Font font;
	Text menu[MAX_POSITION];

};

