#pragma once
#include <iostream>
#include "Player.h"
#include "Exception.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

// Base abstract class for abilities
class Ability
{
public:
	string name;
	int dmg = 0;
	
	bool isAbilityFlying = false; // Used for projectile flight
	bool isUsed = false; // In order not to use the same ability two times in a row
	bool isEnemyCollision = false;

	virtual void draw(RenderWindow& window) = 0;
	virtual void changePlayerTexture(Player& player) = 0;

	// Methods for getting current position
	virtual float getUpEdge() = 0;
	virtual float getDownEdge() = 0;
	virtual float getLeftEdge() = 0;
	virtual float getRightEdge() = 0;
	// Methods for ability movement
	virtual void start(Player& player) = 0; 
	virtual void fly(RenderWindow& window) = 0;
	virtual void disappear() = 0;

};

class IceBall : public Ability
{
public:
	IceBall();
	void draw(RenderWindow& window);
	void changePlayerTexture(Player& player);

	// Methods for getting current position
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();
	// Methods for ability movement
	void start(Player& player);
	void fly(RenderWindow& window);
	void disappear();
private:
	Texture texture;
	Sprite iceBall;
	
};

class FireBall : public Ability
{
public:
	FireBall();
	void draw(RenderWindow& window);
	void changePlayerTexture(Player& player);

	// Methods for getting current position
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();
	// Methods for ability movement
	void start(Player& player);
	void fly(RenderWindow& window);
	void disappear();
private:
	Texture texture;
	Sprite fireBall;
	
};

class LightBall : public Ability
{
public:
	LightBall();
	void draw(RenderWindow& window);
	void changePlayerTexture(Player& player);

	// Methods for getting current position
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();
	// Methods for ability movement
	void start(Player& player);
	void fly(RenderWindow& window);
	void disappear();
private:
	Texture texture;
	Sprite lightBall;

};

