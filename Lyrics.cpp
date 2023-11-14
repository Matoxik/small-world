#include "Lyrics.h"


AbilityLyrics::AbilityLyrics(Ability* abilityPtr)
{
	if (!font.loadFromFile("font_fire.ttf")) 
	{
		Exception* exception = new Exception(2, "Error loading font in the AbilityLyrics class");
		throw exception;
	}

	// Text 1 A - dodge
	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("Dodge");
	text[0].setCharacterSize(45);
	text[0].setPosition(1400, 380);

	// Text 2 W - melee attack
	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("Melee attack");
	text[1].setCharacterSize(45);
	text[1].setPosition(1470, 260);

	// Text 3 S - return
	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("Return");
	text[2].setCharacterSize(45);
	text[2].setPosition(1520, 518);

	// Text 4 D - ability
	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString(abilityPtr->name);
	text[3].setCharacterSize(45);
	text[3].setPosition(1635, 380);



}


void AbilityLyrics::draw(RenderWindow& window)
{
	for (int i = 0; i < NUMBER_OF_LINES; i++)
	{
		window.draw(text[i]);

	}
}

void AbilityLyrics::changeColorAll()
{
	for (int i = 0; i < NUMBER_OF_LINES; i++)
	{
		text[i].setFillColor(Color::Black);
	}
}

void AbilityLyrics::changeColorAbility()
{
	text[3].setFillColor(Color(104, 104, 104, 100));
}

void AbilityLyrics::changeColorDodge()
{
	text[0].setFillColor(Color(104, 104, 104, 100));
}

void AbilityLyrics::changeColorAttack()
{
	text[1].setFillColor(Color(104, 104, 104, 100));
}

void AbilityLyrics::changeColorBack()
{
	text[2].setFillColor(Color(104, 104, 104, 100));
}

// Text after finishing the game attempt
AttemptLyrics::AttemptLyrics(int _attempt)
{
	if (!font.loadFromFile("font_fire.ttf")) 
	{ 
		Exception* exception = new Exception(2, "Error loading font in the AttemptLyrics class");
		throw exception;
	}

	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("Attempt: ");
	text[0].setCharacterSize(50);
	text[0].setPosition(50, 50);


	string attempt = to_string(_attempt);

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString(attempt);
	text[1].setCharacterSize(50);
	text[1].setPosition(200, 50);
}

void AttemptLyrics::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(text[i]);
	}

}

// Text after defeat
DefeatLyrics::DefeatLyrics()
{
	if (!font.loadFromFile("font_fire.ttf")) 
	{
		Exception* exception = new Exception(2, "Error loading font in the DefeatLyrics class");
		throw exception;
	}

	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setString("You lost all your health,\n        Fight again!! ");
	text.setCharacterSize(80);
	text.setPosition(710, 120);

}

void DefeatLyrics::draw(RenderWindow& window)
{
	window.draw(text);
}

// Text after victory
VictoryLyrics::VictoryLyrics()
{
	if (!font.loadFromFile("font_fire.ttf"))
	{ 
		Exception* exception = new Exception(2, "Error loading font in the VictoryLyrics class");
		throw exception;
	}

	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setString("           Congratulations!\nYou defeated the fiery monster ");
	text.setCharacterSize(80);
	text.setPosition(510, 120);

}

void VictoryLyrics::draw(RenderWindow& window)
{
	window.draw(text);
}

// Reading text from a file using 'f'
ReadLyrics::ReadLyrics()
{
	if (!font.loadFromFile("font.ttf"))
	{ 
		Exception* exception = new Exception(2, "Error loading font in the ReadLyrics class");
		throw exception;
	}

	text.setFont(font);
	text.setFillColor(Color(104, 104, 104, 210));
	text.setString("To see the course of the battle,\npress F ");
	text.setCharacterSize(40);
	text.setPosition(1250, 770);

}

void ReadLyrics::draw(RenderWindow& window)
{
	window.draw(text);
}