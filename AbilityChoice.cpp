#include "AbilityChoice.h"


AbilityChoice::AbilityChoice()
{
	// Load the font for rendering text
	if (!font.loadFromFile("font.ttf")) { 
		Exception* exception = new Exception(2, "Error loading font in AbilityChoice class");
		throw exception;
	}

	// Initialize text for the IceBall ability
	text[0].setFont(font);
	text[0].setFillColor(Color::White);
	text[0].setString("IceBall");
	text[0].setCharacterSize(50);
	text[0].setPosition(1420, 400);

	// Initialize text for the FireBall ability
	text[1].setFont(font);
	text[1].setFillColor(Color::White);
	text[1].setString("FireBall");
	text[1].setCharacterSize(50);
	text[1].setPosition(900, 400);

	// Initialize text for the LightBall ability
	text[2].setFont(font);
	text[2].setFillColor(Color::White);
	text[2].setString("LightBall");
	text[2].setCharacterSize(50);
	text[2].setPosition(380, 400);

	// Initialize introduction text
	text[3].setFont(font);
	text[3].setFillColor(Color::White);
	text[3].setString("        To escape, you must first defeat the Fire Monster,\n   which you will encounter after crossing the portal. The only\n     way I can help you is by granting you a chosen Ability.\n             Think for a moment and choose wisely!");
	text[3].setCharacterSize(50);
	text[3].setPosition(200, 100);

	choice = -1;
}

// Method to handle button press and return the selected choice
int AbilityChoice::buttonPress()
{
	return choice;
}

// Method to draw the AbilityChoice menu on the specified window
void AbilityChoice::draw(RenderWindow& window)
{
	for (int i = 0; i < NUMBER_OF_DIALOGUES; i++)
	{
		window.draw(text[i]);
	}
}

// Method to move the selection cursor up
void AbilityChoice::moveUp()
{
	if (choice - 1 >= 0)
	{
		text[choice].setFillColor(Color::White);

		choice--;
		if (choice == -1)
		{
			choice = 2;
		}
		text[choice].setFillColor(Color(21, 222, 242, 220));
	}
}

// Method to move the selection cursor down
void AbilityChoice::moveDown()
{
	if (choice + 1 <= 3)
	{
		text[choice].setFillColor(Color::White);

		choice++;
		if (choice == 3)
		{
			choice = 0;
		}
		text[choice].setFillColor(Color(21, 222, 242, 220));
	}
}