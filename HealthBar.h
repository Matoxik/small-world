#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Enemy.h"
#include "Exception.h"

using namespace sf;
using namespace std;

class HealthBar
{
public:
	HealthBar();

	void draw(RenderWindow& window);

	void updatePlayer(Player& player);
	void updateEnemy(Enemy& enemy);

	
private:
	Texture texture;
	Sprite healthBar[2];
};
