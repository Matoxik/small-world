#pragma once
#include <iostream>

#include "time.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Exception.h"

using namespace sf;
using namespace std;

#define MAX_PLAYER_HEALTH 6

class Player
{
public:
	Player();
	// Flags used in Ability class
	bool isPlayerLight = false;
	bool isPlayerFire = false;
	bool isPlayerIce = false;
	
	bool isMidDodge = false;
	bool isDodge = false;

	void draw(RenderWindow& window);

	// Methods for getting current position of the player
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();
	
	// Update player movement
	void update();
	
	// Methods for choosing player texture based on elemental flags
	void setIceTexture();
	void setFireTexture();
	void setLightTexture();
	void setBasicTexture();

	// Combat methods
	void dodgeRight();
	void dodgeLeft();
	void dodgeMiddle();
	void setAttack();
	void setBack();
	void setToFight();
	void setStartPosition();
	
	// Health management
	friend void takeAwayHealth(Player& obiekt, int howMuch);
	void addHealth();
	bool checkHealth();
	void resetHealth();
	int getHealth();

	
private:
	int playerHealth;
	int addHealthRandom = 0;

	float xVelocity = 6;
	float yVelocity = 6;
	
	Texture texture;
	Sprite player;
	
};



