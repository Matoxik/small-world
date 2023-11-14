#pragma once
#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string> 

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Ability.h"
#include "Exception.h"


#define NUMBER_OF_LINES 4

using namespace sf;
using namespace std;

// Class for displaying lyrics related to abilities during gameplay
class AbilityLyrics
{
public:
	AbilityLyrics(Ability* abilityPtr);
	void draw(RenderWindow& window);
	void changeColorAll();
	void changeColorAbility();
	void changeColorDodge();
	void changeColorAttack();
	void changeColorBack();

private:

	Font font;
	Text text[NUMBER_OF_LINES];

};

// Class for displaying lyrics related to attempts during the game
class AttemptLyrics
{
public:
	AttemptLyrics(int attempt);
	void draw(RenderWindow& window);
private:
	Font font;
	Text text[2];
};

// Class for displaying defeat-related lyrics
class DefeatLyrics
{
public:
	DefeatLyrics();
	void draw(RenderWindow& window);
private:
	Font font;
	Text text;
};

// Class for displaying victory-related lyrics
class VictoryLyrics
{
public:
	VictoryLyrics();
	void draw(RenderWindow& window);
private:
	Font font;
	Text text;
};

// Class for displaying general lyrics
class ReadLyrics
{
public:
	ReadLyrics();
	void draw(RenderWindow& window);
private:
	Font font;
	Text text;
};