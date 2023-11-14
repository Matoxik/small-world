#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Exception.h"


using namespace sf;

// Abstract base class representing a portal
class Portal
{
public:
	// Virtual functions to get the edges of the portal
	virtual float getUpEdge() = 0;
	virtual float getDownEdge() = 0;
	virtual float getLeftEdge() = 0;
	virtual float getRightEdge() = 0;

};

class Portal_1 : public Portal
{
public:
	Portal_1();

	// Implementation of virtual functions to get the edges of the portal
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();
	
	void changeTexture();

	void draw(RenderWindow& window);

private:
	Texture textureFirst;
	Texture textureSecond;
	Sprite portal_1;
};

class Portal_2 : public Portal
{
public:
	Portal_2();

	// Implementation of virtual functions to get the edges of the portal
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();

	void draw(RenderWindow& window);
private:
	Texture texture;
	Sprite portal_2;
};

class Portal_3 : public Portal
{
public:
	Portal_3();

	// Implementation of virtual functions to get the edges of the portal
	float getUpEdge();
	float getDownEdge();
	float getLeftEdge();
	float getRightEdge();

	void draw(RenderWindow& window);
private:

	Texture texture;
	Sprite portal_3;
};
