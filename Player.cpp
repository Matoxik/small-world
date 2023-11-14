#include "Player.h"

Player::Player()
{
    // Load texture for the player
    if (!texture.loadFromFile("textures/ludzik.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture in Player class");
        throw exception;
    }
    // Set up the player sprite
    player.setTexture(texture);
    player.setTextureRect({ 50,55,400,330 });
    player.setPosition(900, 600);
    player.setScale(0.5, 0.5);
    player.setOrigin(200, 165); // Setting the center of the player

    playerHealth = MAX_PLAYER_HEALTH;
}

void Player::draw(RenderWindow& window)
{
    window.draw(player);
}

// Update player movement based on key presses
void Player::update()
{
    if ((Keyboard::isKeyPressed(Keyboard::Right)) && (this->getRightEdge() < 1920))  player.move(xVelocity, 0);
    if ((Keyboard::isKeyPressed(Keyboard::Left)) && (this->getLeftEdge() > 0))  player.move(-xVelocity, 0);
    if ((Keyboard::isKeyPressed(Keyboard::Up)) && (this->getUpEdge() > 0))   player.move(0, -yVelocity);
    if ((Keyboard::isKeyPressed(Keyboard::Down)) && (this->getDownEdge() < 1080))  player.move(0, yVelocity);
}


// Methods for getting current position
float Player::getUpEdge()
{
    return this->player.getPosition().y - 82;  
}

float Player::getDownEdge()
{
    return this->player.getPosition().y + 82; 
}

float Player::getLeftEdge()
{
    return this->player.getPosition().x - 100; 
}

float Player::getRightEdge()
{
    return this->player.getPosition().x + 100; 
}


void Player::setBasicTexture()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        player.setTextureRect({ 50,55,400,330 });
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        player.setTextureRect({ 535,55,400,330 });
    }
}

void Player::setIceTexture()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        player.setTextureRect({ 950,55,400,330 });
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        player.setTextureRect({ 1440,55,400,330 });
    }

}

void Player::setFireTexture()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        player.setTextureRect({ 50,530,400,330 });
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        player.setTextureRect({ 545,530,400,330 });
    }

}

void Player::setLightTexture()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        player.setTextureRect({ 960,530,400,330 });
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        player.setTextureRect({ 1450,530,400,330 });
    }

}

// Combat
void Player::dodgeRight()
{
    if (isPlayerIce == true) player.setTextureRect({ 1440,55,400,330 });
    if (isPlayerFire == true) player.setTextureRect({ 545,530,400,330 });
    if (isPlayerLight == true) player.setTextureRect({ 1450,530,400,330 });

    if (this->getLeftEdge() < 1160)
    {
        player.move(7, 0);

    }
    else isDodge = false;
}

void Player::dodgeMiddle()
{

    if (this->getLeftEdge() >= 800)
    {
        if (isPlayerIce == true) player.setTextureRect({ 950,55,400,330 });
        if (isPlayerFire == true) player.setTextureRect({ 50,530,400,330 });
        if (isPlayerLight == true) player.setTextureRect({ 960,530,400,330 });

        player.move(-7, 0);
        isMidDodge = true;

    }
    else if ((this->getLeftEdge() <= 800) && (isMidDodge == false))
    {
        if (isPlayerIce == true) player.setTextureRect({ 1440,55,400,330 });
        if (isPlayerFire == true)  player.setTextureRect({ 545,530,400,330 });
        if (isPlayerLight == true)  player.setTextureRect({ 1450,530,400,330 });


        player.move(7, 0);
    }

    else
    {
        isDodge = false;
        isMidDodge = false;
    }

}

void Player::dodgeLeft()
{
    if (isPlayerIce == true) player.setTextureRect({ 950,55,400,330 });
    if (isPlayerFire == true) player.setTextureRect({ 50,530,400,330 });
    if (isPlayerLight == true) player.setTextureRect({ 960,530,400,330 });

    if (this->getLeftEdge() > 500)
    {
        player.move(-7, 0);

    }
    else isDodge = false;

}
// Move up
void Player::setAttack()
{
    if (this->getUpEdge() > 300) player.move(0, -9);
}
// Move down
void Player::setBack()
{
    if (this->getDownEdge() < 800) player.move(0, 9);
}

void Player::addHealth()
{
    addHealthRandom = rand() % 2;
    if ((addHealthRandom == 0) && (playerHealth < MAX_PLAYER_HEALTH)) playerHealth++;
}

bool Player::checkHealth()
{
    if (playerHealth <= 0) return true;
    else return false;
}

void Player::resetHealth()
{
    this->playerHealth = MAX_PLAYER_HEALTH;
}

int Player::getHealth()
{
    return this->playerHealth;
}

void Player::setToFight()
{
    player.setPosition(935, 700);
}

void Player::setStartPosition()
{
    player.setPosition(440, 400);
}



