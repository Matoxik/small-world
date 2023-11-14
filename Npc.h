#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Exception.h"

using namespace sf;

// Class of NPC, dialogue character
class Npc
{
public:
	Npc();
	void draw(RenderWindow& window);
	
	// Methods for getting current position
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();
	

private:
	Texture texture;
	Sprite npc;
};
