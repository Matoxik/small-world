#include "StartDialogue.h"

// StartDialogue
StartDialogue::StartDialogue()
{
	// Load the font
	if (!font.loadFromFile("font.ttf")) { 
		Exception* exception = new Exception(2, "Error loading font in StartDialogue class");
		throw exception;
	}
	// Initialize the start dialogue text
	textStart.setFont(font);
	textStart.setFillColor(Color::Black);
	textStart.setString("    Hello traveler!\n  It seems you're also\n     stuck in this\n  seemingly beautiful\n   land. Don't worry,\n     come closer\n    and we'll talk.");
	textStart.setCharacterSize(35);
	textStart.setPosition(1120, 180);
}


void StartDialogue::draw(RenderWindow& window)
{
	window.draw(textStart);
}

// Method to change the text in the dialogue
void StartDialogue::text_2()
{
	textStart.setString("\n  Remember that the\n  Monster will attack\n  you when you get\n  closer.\n       Good luck!");
}



// DialogueCloud
DialogueCloud::DialogueCloud()
{
	if (!texture.loadFromFile("textures/chmurkaDialogowa.png"))
	{
		Exception* exception = new Exception(3, "Error loading texture for DialogueCloud class");
		throw exception;
	}
	cloud.setTexture(texture);
	cloud.setPosition(1110, 150);
	cloud.setScale(0.5, 0.5);
}

void DialogueCloud::draw(RenderWindow& window)
{
	window.draw(cloud);
}