#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Exception.h"


using namespace sf;

#define MAX_ENEMY_HEALTH 6

// Class representing an enemy in the game
class Enemy
{
public:
	Enemy();

	void draw(RenderWindow& window);
	// Methods for getting current position
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();
	
	void changePosition();
	void disappear();


	// Health management functions
	friend void takeAwayHealth(Enemy& obiekt, int howMuch);
	bool checkHealth();
	void resetHealth(); // Reset the enemy's health to the maximum
	int getHealth();


private:
	Texture texture;
	Sprite enemy;

	int enemyHealth;
};
