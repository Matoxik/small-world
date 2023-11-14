#include "Credits.h"


Credits::Credits()
{
	// // Load the font for rendering text
	if (!font.loadFromFile("font.ttf")) 
	{
		Exception* exception = new Exception(2, "Error loading font in Credits class");
		throw exception;
	}

	// Text 1: Tester
	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("Tester: MA ");
	text[0].setCharacterSize(100);
	text[0].setPosition(650, -800);

	// Text 2: Graphics
	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("Graphics: MA ");
	text[1].setCharacterSize(100);
	text[1].setPosition(650, -500);

	// Text 3: Programmer
	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("Coding: MA");
	text[2].setCharacterSize(100);
	text[2].setPosition(650, -200);
}

// Draw method to display the credits on the window
void Credits::draw(RenderWindow& window)
{
	for (int i = 0; i < NUMBER_OF_LINES_CR; i++)
	{
		window.draw(text[i]);
		if (text[NUMBER_OF_LINES_CR - 1].getPosition().y < 700)
			text[i].move(0, 0.12);
	}
}

