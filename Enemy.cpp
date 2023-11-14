#include "Enemy.h"

Enemy::Enemy()
{
    // Load the enemy texture
    if (!texture.loadFromFile("textures/potworek2.png"))
    {
        Exception* exception = new Exception(3, "Error loading texture in Enemy class");
        throw exception;
    }
    // Set up the enemy sprite with initial position and health
    enemy.setTexture(texture);
    enemy.setPosition(1000, 550);
    enemy.setOrigin(225, 225);
    enemyHealth = MAX_ENEMY_HEALTH;
}

void Enemy::draw(RenderWindow& window)
{
    window.draw(enemy);
}

// Methods for getting current position
float Enemy::getUpEdge()
{
    return this->enemy.getPosition().y - 180;  
}

float Enemy::getDownEdge()
{
    return this->enemy.getPosition().y + 180;
}

float Enemy::getLeftEdge()
{
    return this->enemy.getPosition().x - 110; 
}

float Enemy::getRightEdge()
{
    return this->enemy.getPosition().x + 135;
}

void Enemy::changePosition()
{
    enemy.setPosition(925, 180);
}

void Enemy::disappear()
{
    enemy.setPosition(2200, 300);
}

bool Enemy::checkHealth()
{
    if (enemyHealth <= 0) return true;
    else return false;
}

void Enemy::resetHealth()
{
    this->enemyHealth = MAX_ENEMY_HEALTH;
}

int Enemy::getHealth()
{
    return this->enemyHealth;
}