#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Exception.h"

using namespace std;
using namespace sf;

class MenuBackground
{

public:
	MenuBackground();
	void draw(RenderWindow& window);

private:
	RectangleShape backgroundShape; // Shape representing the background
	Texture backgroundTexture;

};

class StartBackground
{

public:
	StartBackground();
	void draw(RenderWindow& window);

private:
	RectangleShape backgroundShape; // Shape representing the background
	Texture backgroundTexture;

};

class FirstLevelBackground
{

public:
	FirstLevelBackground();
	void draw(RenderWindow& window);

private:
	RectangleShape backgroundShape; // Shape representing the background
	Texture backgroundTexture;

};

class FightBackground
{

public:
	FightBackground();
	void draw(RenderWindow& window);

private:
	RectangleShape backgroundShape; // Shape representing the background
	Texture backgroundTexture;

};

//lawa
class Lava
{
public:
	Lava();
	void draw(RenderWindow& window);


private:
	Texture texture;
	Sprite lava;
};
