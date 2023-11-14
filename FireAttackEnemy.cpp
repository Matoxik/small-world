#include "FireAttackEnemy.h"

FireAttackEnemy::FireAttackEnemy()
{
    // Load the texture for the fire attack
    if (!texture.loadFromFile("textures/fireball.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture in FireAttackEnemy class");
        throw exception;
    }

    // Set properties for the fire attack sprite
    fireAttack.setTexture(texture);
    fireAttack.setScale(0.4, 0.4);
    fireAttack.setRotation(-200);
    fireAttack.setOrigin(256, 256);

    // Generate a random number for positioning the fire attack
    random = rand() % 6;
    setFireAttackRandom();
}

// Methods for getting current position
float FireAttackEnemy::getUpEdge()
{
    return this->fireAttack.getPosition().y - 77; 
}

float FireAttackEnemy::getDownEdge()
{
    return this->fireAttack.getPosition().y + 72; 
}

float FireAttackEnemy::getLeftEdge()
{
    return this->fireAttack.getPosition().x - 70;
}

float FireAttackEnemy::getRightEdge()
{
    return this->fireAttack.getPosition().x + 71; 
}


void FireAttackEnemy::setFireAttackRandom()
{
    if (random < 0 || random>5)
    {
        Exception* exception = new Exception(4, "Error in randomization in FireAttackEnemy class");
        throw exception;
    }
    switch (random)
    {

    case 0: // Left position
    {
        fireAttack.setPosition(625, -500);

    }
    break;
    case 1: // Middle position 
    {
        fireAttack.setPosition(925, -500);
    }
    break;
    case 2: // Right position 
    {
        fireAttack.setPosition(1225, -500);
    }
    break;
    case 3:
    {
        fireAttack.setPosition(625, -200);
    }
    break;
    case 4:
    {
        fireAttack.setPosition(925, -200);
    }
    break;
    case 5:
    {
        fireAttack.setPosition(1225, -200);
    }
    break;
    }
}


void FireAttackEnemy::draw(RenderWindow& window)
{
    window.draw(fireAttack);
    fireAttack.move(0, 3);
}



void  FireAttackEnemy::start()
{
    if (fireAttack.getPosition().y > 300) isFireAttackShot = true;

}

// Method to check if the fire attack should be deleted (if it goes beyond a window)
bool FireAttackEnemy::deleteFireAttack()
{
    if (fireAttack.getPosition().y > 1050) return true;
    else return false;
}

void FireAttackEnemy::disappear()
{
    fireAttack.setPosition(200, 1200);
}