#include "HealthBar.h"


HealthBar::HealthBar()
{
    // Loading health bar texture
    if (!texture.loadFromFile("textures/zdrowie.png"))
    {
        Exception* exception = new Exception(3, "Error loading textures in HealthBar class");
        throw exception;
    }
    
    // Player health bar
    healthBar[0].setTexture(texture);
    healthBar[0].setPosition(200, 800);
    healthBar[0].setScale(0.4, 0.4);
   
    // Enemy health bar
    healthBar[1].setTexture(texture);
    healthBar[1].setPosition(1350, 100);
    healthBar[1].setScale(0.4, 0.4);

}

void HealthBar::draw(RenderWindow& window)
{
    for (int i = 0; i < 2; i++)
    {
        window.draw(healthBar[i]);
    }
}

void HealthBar::updatePlayer(Player& player)
{
    healthBar[0].setTextureRect({ 0,(player.getHealth() - 1) * 184 - 24,650,180 });
}

void HealthBar::updateEnemy(Enemy& enemy)
{
    healthBar[1].setTextureRect({ 0,(enemy.getHealth() - 1) * 184 - 24,650,180 });
}