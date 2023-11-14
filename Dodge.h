#pragma once
#include <iostream>
#include "Player.h"
#include "Exception.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
using namespace std;

// Class used during fight versus enemy as a "dodge" function
class Dodge
{
public:
	Dodge();
	int random = 0; // Variable used for randomization during dodging
	void dodgeAbility(Player& player);
};
