#include "Portal.h"

// Portal_1
Portal_1::Portal_1()
{
    if (!textureFirst.loadFromFile("textures/portal1v1.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture in Portal_1 class ");
        throw exception;
    }
    // Set up initial properties
    portal_1.setTexture(textureFirst);
    portal_1.setPosition(180, 190);
    portal_1.setScale(0.6, 0.6);
    portal_1.setOrigin(193, 243); // Setting the center of the character
}

// Methods for getting current position
float Portal_1::getUpEdge()
{
    return this->portal_1.getPosition().y - 80;  
}

float Portal_1::getDownEdge()
{
    return this->portal_1.getPosition().y + 80; 
}

float Portal_1::getLeftEdge()
{
    return this->portal_1.getPosition().x - 40; 
}

float Portal_1::getRightEdge()
{
    return this->portal_1.getPosition().x + 40;
}


void Portal_1::draw(RenderWindow& window)
{
    window.draw(portal_1);
}

void Portal_1::changeTexture()
{
    if (!textureSecond.loadFromFile("textures/portal1v2.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture after change in Portal_1 class ");
        throw exception;
    }
    
    portal_1.setTexture(textureSecond);
    portal_1.setScale(0.6, 0.6);
    portal_1.setTextureRect({ 0,0,383,486 });
}


// Portal 2
Portal_2::Portal_2()
{
    if (!texture.loadFromFile("textures/portal2v1.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture in Portal_2 class");
        throw exception;
    }
    // Set up initial properties
    portal_2.setTexture(texture);
    portal_2.setPosition(180, 750);
    portal_2.setScale(0.6, 0.6);
    portal_2.setOrigin(172, 246); // Setting the center of the character
}

// Methods for getting current position
float Portal_2::getUpEdge()
{
    return this->portal_2.getPosition().y - 80;  
}

float Portal_2::getDownEdge()
{
    return this->portal_2.getPosition().y + 80;
}

float Portal_2::getLeftEdge()
{
    return this->portal_2.getPosition().x - 40;
}

float Portal_2::getRightEdge()
{
    return this->portal_2.getPosition().x + 40;
}


void Portal_2::draw(RenderWindow& window)
{
    window.draw(portal_2);
}



// Portal_3
Portal_3::Portal_3()
{
    if (!texture.loadFromFile("tekstura2.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture in Portal_3 class");
        throw exception;
    }
    portal_3.setTexture(texture);
    // portal_3.setTextureRect({ 50,610,250,206 });
    portal_3.setPosition(1500, 100);
    portal_3.setScale(0.2, 0.2);
    //portal_3.setOrigin(150, 150);
}

// Methods for getting current position
float Portal_3::getUpEdge()
{
    return this->portal_3.getPosition().y - 110;  
}

float Portal_3::getDownEdge()
{
    return this->portal_3.getPosition().y + 110; 
}

float Portal_3::getLeftEdge()
{
    return this->portal_3.getPosition().x + 20; 
}

float Portal_3::getRightEdge()
{
    return this->portal_3.getPosition().x + 140; 
}


void Portal_3::draw(RenderWindow& window)
{
    window.draw(portal_3);
}

