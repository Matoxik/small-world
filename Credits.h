#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Exception.h"

#define NUMBER_OF_LINES_CR 3

using namespace sf;
using namespace std;

class Credits
{
public:
	Credits();
	void draw(RenderWindow& window);

private:
	Font font;
	Text text[NUMBER_OF_LINES_CR];
};

