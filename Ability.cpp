#include "Ability.h"

// Method definitions of IceBall class
IceBall::IceBall()
{
    // Load the texture for the ice ball and handle loading errors
    if (!texture.loadFromFile("textures/iceball.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture for IceBall in Ability class");
        throw exception;
    }
    // Set up the properties of the ice ball
    iceBall.setTexture(texture);
    iceBall.setPosition(1490, 640);
    iceBall.setScale(0.13, 0.13);
    iceBall.setRotation(-45);
    iceBall.setOrigin(634, 723);

    name = "IceBall";
    dmg = 4;
}

// Methods for getting current position
float IceBall::getUpEdge()
{
    return this->iceBall.getPosition().y - 86; 
}

float IceBall::getDownEdge()
{
    return this->iceBall.getPosition().y + 50; 
}

float IceBall::getLeftEdge()
{
    return this->iceBall.getPosition().x - 55;
}

float IceBall::getRightEdge()
{
    return this->iceBall.getPosition().x + 55; 
}

// Draw the ice ball on the specified window
void IceBall::draw(RenderWindow& window)
{
    window.draw(iceBall);
}

// Change the player's texture to ice
void IceBall::changePlayerTexture(Player& player)
{
    player.setIceTexture();
    player.isPlayerIce = true;
}

// Set the initial position and activate the ice ball
void IceBall::start(Player& player)
{
    iceBall.setPosition(player.getLeftEdge() + 95, player.getUpEdge());
    this->isAbilityFlying = true;
}

// Move the ice ball upwards
void IceBall::fly(RenderWindow& window)
{
    window.draw(iceBall);
    iceBall.move(0, -4);

}

// Reset the position of the ice ball and deactivate it
void IceBall::disappear()
{
    iceBall.setPosition(200, -50);
    this->isAbilityFlying = false;
}

// Method definitions of FireBall class
FireBall::FireBall()
{
    // Load the texture for the fire ball and handle loading errors
    if (!texture.loadFromFile("textures/ognista.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture for FireBall in Ability class");
        throw exception;
    }
    // Set up the properties of the fire ball
    fireBall.setTexture(texture);
    fireBall.setOrigin(400, 440);
    fireBall.setRotation(120);
    fireBall.setPosition(980, 640);
    fireBall.setScale(0.18, 0.18);

    name = "FireBall";
    dmg = 0;
}

// Methods for getting current position
float FireBall::getUpEdge()
{
    return this->fireBall.getPosition().y - 54;  
}

float FireBall::getDownEdge()
{
    return this->fireBall.getPosition().y + 54; 
}

float FireBall::getLeftEdge()
{
    return this->fireBall.getPosition().x - 45; 
}

float FireBall::getRightEdge()
{
    return this->fireBall.getPosition().x + 45; 
}

// Draw the fire ball on the specified window
void FireBall::draw(RenderWindow& window)
{
    window.draw(fireBall);
}

// Change the player's texture to fire
void FireBall::changePlayerTexture(Player& player)
{
    player.setFireTexture();
    player.isPlayerFire = true;
}

// Set the initial position and activate the fire ball
void FireBall::start(Player& player)
{
    fireBall.setPosition(player.getLeftEdge() + 90, player.getUpEdge());
    this->isAbilityFlying = true;
}

// Move the fire ball upwards
void FireBall::fly(RenderWindow& window)
{
    window.draw(fireBall);
    fireBall.move(0, -4);

}

// Reset the position of the fire ball and deactivate it
void FireBall::disappear()
{
    fireBall.setPosition(200, -50);
    this->isAbilityFlying = false;
}

// Method definitions of LightBall class
LightBall::LightBall()
{
    // Load the texture for the light ball and handle loading errors
    if (!texture.loadFromFile("textures/swietlistyPocisk.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture for LightBall in Ability class");
        throw exception;
    }
    // Set up the properties of the light ball
    lightBall.setTexture(texture);
    lightBall.setOrigin(585, 327);
    lightBall.setPosition(400, 700);
    lightBall.setScale(0.33, 0.33);
    lightBall.setRotation(240);

    name = "LightBall";
    dmg = 2;
}

// Methods for getting current position
float LightBall::getUpEdge()
{
    return this->lightBall.getPosition().y - 72;  
}

float LightBall::getDownEdge()
{
    return this->lightBall.getPosition().y + 76;
}

float LightBall::getLeftEdge()
{
    return this->lightBall.getPosition().x - 72; 
}

float LightBall::getRightEdge()
{
    return this->lightBall.getPosition().x + 72; 
}

// Draw the light ball on the specified window
void LightBall::draw(RenderWindow& window)
{
    window.draw(lightBall);
}

// Change the player's texture to light
void LightBall::changePlayerTexture(Player& player)
{
    player.setLightTexture();
    player.isPlayerLight = true;
}

// Set the initial position and activate the light ball
void LightBall::start(Player& player)
{
    lightBall.setPosition(player.getLeftEdge() + 20, player.getUpEdge());
    this->isAbilityFlying = true;
}

// Move the light ball upwards
void LightBall::fly(RenderWindow& window)
{
    window.draw(lightBall);
    lightBall.move(0, -4);

}

// Reset the position of the light ball and deactivate it
void LightBall::disappear()
{
    lightBall.setPosition(200, -50);
    this->isAbilityFlying = false;
}
