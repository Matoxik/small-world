#pragma once

#include <iostream>

#include "Exception.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
using namespace std;

class FireAttackEnemy
{
public:
	bool isPlayerCollision = false; // Flag to indicate collision with the player
	bool isFireAttackShot = false;
	int random = 0; // Variable used for randomization
	int dmgFireAttack = 2; // Damage inflicted by the fire attack

	FireAttackEnemy();

	void draw(RenderWindow& window);
	
	// Methods for getting current position
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();

	bool deleteFireAttack(); 
	void setFireAttackRandom();  
	void disappear();
	void start();

private:
	Texture texture;
	Sprite fireAttack;

};
