#include "Npc.h"


Npc::Npc()
{
    // Loading texture for the NPC
    if (!texture.loadFromFile("textures/npc.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture in Npc class");
        throw exception;
    }
    // Set up Npc properties
    npc.setTexture(texture);
    npc.setPosition(1520, 550);
    npc.setScale(0.5, 0.5);
    npc.setOrigin(189, 295); // Set up the middle of the character as the origin
}

void Npc::draw(RenderWindow& window)
{
    window.draw(npc);
}

float Npc::getUpEdge()
{
    return this->npc.getPosition().y - 140;  
}

float Npc::getDownEdge()
{
    return this->npc.getPosition().y + 140; 
}

float Npc::getLeftEdge()
{
    return this->npc.getPosition().x - 83; 
}

float Npc::getRightEdge()
{
    return this->npc.getPosition().x + 83;
}