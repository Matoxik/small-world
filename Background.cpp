#include "Background.h"


// Method definitions of MenuBackground class
MenuBackground::MenuBackground()
{
    // Load the texture for the menu background
    if (!backgroundTexture.loadFromFile("textures/menu2.jpg"))
    {
        Exception* exception = new Exception(3, "Error loading menu background texture");
        throw exception;
    }
  
    // Set the texture for the background shape and define its size
    backgroundShape.setTexture(&backgroundTexture);
    backgroundShape.setSize(Vector2f(1920, 1080));
}

void MenuBackground::draw(RenderWindow& window)
{
    window.draw(backgroundShape);
}


// Method definitions of MenuBaFirstLevelBackground class
FirstLevelBackground::FirstLevelBackground()
{
    // Load the texture for the first level background
    if (!backgroundTexture.loadFromFile("textures/tlopoziom1.png"))
    {
        Exception* exception = new Exception(3, "Error loading first level background texture in FirstLevelBackground class ");
        throw exception;
    }
    // Set the texture for the background shape and define its size
    backgroundShape.setTexture(&backgroundTexture);
    backgroundShape.setSize(Vector2f(1920, 1080));
}

void FirstLevelBackground::draw(RenderWindow& window)
{
    window.draw(backgroundShape);
}

// Method definitions of FightBackground class
FightBackground::FightBackground()
{
    // Load the texture for the fight background
    if (!backgroundTexture.loadFromFile("textures/tloWalka.png"))
    {
        Exception* exception = new Exception(3, "Error loading fight background texture in FightBackground class ");
        throw exception;
    }
    // Set the texture for the background shape and define its size
    backgroundShape.setTexture(&backgroundTexture);
    backgroundShape.setSize(Vector2f(1920, 1080));
}

void FightBackground::draw(RenderWindow& window)
{
    window.draw(backgroundShape);
}

// Method definitions of StartBackground class
StartBackground::StartBackground()
{
    // Load the texture for the start background
    if (!backgroundTexture.loadFromFile("textures/tloStart.png"))
    {
        Exception* exception = new Exception(3, "Error loading start background texture in StartBackground class ");
        throw exception;
    }
    // Set the texture for the background shape and define its size
    backgroundShape.setTexture(&backgroundTexture);
    backgroundShape.setSize(Vector2f(1920, 1080));
}

void StartBackground::draw(RenderWindow& window)
{
    window.draw(backgroundShape);
}

// Method definitions of Lava class
Lava::Lava()
{
    // Load the texture for the lava
    if (!texture.loadFromFile("textures/lava.png"))
    {
        Exception* exception = new Exception(3, "Error loading lava texture");
        throw exception;
    }
    // Set the texture for the lava sprite and define its position and scale
    lava.setTexture(texture);
    lava.setPosition(-230, 550);
    lava.setScale(0.8, 0.8);

}

void Lava::draw(RenderWindow& window)
{
    window.draw(lava);
}
