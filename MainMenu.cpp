#include "MainMenu.h"


MainMenu::MainMenu(float width, float height)
{
	// Loading the font
	if (!font.loadFromFile("font.ttf")) 
	{ 
		Exception* exception = new Exception(2, "Error loading font in MainMenu class");
		throw exception;
	}

	// Start the adventure
	menu[0].setFont(font);
	menu[0].setFillColor(Color::White);
	menu[0].setString("Start the adventure!");
	menu[0].setCharacterSize(100);
	menu[0].setPosition(650, 200);
	
	// Credits
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Credits");
	menu[1].setCharacterSize(100);
	menu[1].setPosition(650, 450);

	//Exit
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(100);
	menu[2].setPosition(650, 700);

	ChoiceMainMenu = -1;
}

MainMenu::~MainMenu()
{

}

void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_POSITION; i++)
	{
		window.draw(menu[i]);
	}
}

void MainMenu::moveUp()
{
	if (ChoiceMainMenu - 1 >= 0)
	{
		menu[ChoiceMainMenu].setFillColor(Color::White);

		ChoiceMainMenu--;
		if (ChoiceMainMenu == -1)
		{
			ChoiceMainMenu = 2;
		}
		menu[ChoiceMainMenu].setFillColor(Color::Black);
	}
}

void MainMenu::moveDown()
{
	if (ChoiceMainMenu + 1 <= MAX_POSITION)
	{
		menu[ChoiceMainMenu].setFillColor(Color::White);

		ChoiceMainMenu++;
		if (ChoiceMainMenu == 3)
		{
			ChoiceMainMenu = 0;
		}
		menu[ChoiceMainMenu].setFillColor(Color::Black);
	}
}
