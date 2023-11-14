#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include "time.h"

#include <vector>
#include <string>
#include <fstream>

#include "Player.h"
#include "Dodge.h"
#include "Enemy.h"
#include "FireAttackEnemy.h"
#include "Ability.h"
#include "Exception.h"
#include "HealthBar.h"
#include "Npc.h"
#include "StartDialogue.h"
#include "AbilityChoice.h"
#include "Portal.h"
#include "MainMenu.h"
#include "Background.h"
#include "Lyrics.h"
#include "Credits.h"


using namespace std;
using namespace sf;

// Closing windows
bool isMainWindowClosed = false; 
bool isDialogueWindowClosed = false;
bool isFightWindowClosed = false;

// Points to an object of Ability child class 
Ability* abilityPtr; 


// Is there an intersection of two objects
template <class T1, class T2> bool isIntersection(T1& A, T2& B)
{
    return A.getRightEdge() >= B.getLeftEdge() && A.getLeftEdge() <= B.getRightEdge()
        && A.getDownEdge() >= B.getUpEdge() && A.getUpEdge() <= B.getDownEdge();
}

// Collisions
bool isPlayerPortalCollision(Player& player, Portal& portal)
{
    if (!isIntersection(player, portal)) return false;
    else return true;
}

bool isPlayerNpcCollision(Player& player, Npc& npc)
{
    if (!isIntersection(player, npc)) return false;
    else return true;
}

bool isPlayerEnemyCollision(Player& player, Enemy& enemy)
{
    if (!isIntersection(player, enemy)) return false;
    else return true;
}
bool isPlayerFireAttackEnemyCollision(Player& player, FireAttackEnemy& fireAttack)
{
    if (!isIntersection(player, fireAttack)) return false;
    else return true;
}
bool isAbilityEnemyCollision(Ability& ability, Enemy& enemy)
{
    if (!isIntersection(ability, enemy)) return false;
    else return true;
}
bool isAbilityFireAttackEnemyCollision(Ability& ability, FireAttackEnemy& fireAttack)
{
    if (!isIntersection(ability, fireAttack)) return false;
    else return true;
}

Ability* abilityChoice(int choice, RenderWindow& window)
{
    switch (choice)
    {
    case 0:
    {
        window.close();
        isDialogueWindowClosed = true;
        return new IceBall;
    }
    break;
    case 1:
    {
        window.close();
        isDialogueWindowClosed = true;
        return new FireBall;
    }
    break;
    case 2:
    {
        window.close();
        isDialogueWindowClosed = true;
        return new LightBall;
    }
    break;
    default: return nullptr;
    }
}

// How much health it will take from enemy
void takeAwayHealth(Enemy& enemy, int howMuch)  
{
    enemy.enemyHealth = enemy.enemyHealth - howMuch;
}
// How much health it will take from player
void takeAwayHealth(Player& player, int howMuch)
{
    player.playerHealth = player.playerHealth - howMuch;
}

void read()
{
    string buf;
    ifstream fightProcess("fightProcess.txt");
    while (getline(fightProcess, buf))
        cout << buf << '\n';
}

// Used during fight in collision between player's ability and enemy's fire attack
int operator+(Ability* abilityPtr, FireAttackEnemy fireAttack)
{
    int finalDmg;
    finalDmg = abilityPtr->dmg - fireAttack.dmgFireAttack;
    return finalDmg;
}

int main()
{
    srand(time(NULL));
    ofstream errors("Errors.txt", ios::trunc);

    try
    {
        // Creating menu window
        RenderWindow menuWindow(VideoMode(1920, 1080, 32), "Menu");
        MainMenu menu(menuWindow.getSize().x, menuWindow.getSize().y);

        MenuBackground menuBackground;

        
        while (menuWindow.isOpen())  
        {
            Event menuEvent;
            while (menuWindow.pollEvent(menuEvent))
            {

                if (menuEvent.type == Event::Closed)
                {
                    menuWindow.close();
                }

                if (menuEvent.type == Event::KeyReleased)
                {
                    if (menuEvent.key.code == Keyboard::Up)
                    {
                        menu.moveUp();
                        break;
                    }
                    if (menuEvent.key.code == Keyboard::Down)
                    {
                        menu.moveDown();
                        break;
                    }
                    if (menuEvent.key.code == Keyboard::Return)
                    {
                        // Creating start window
                        RenderWindow startWindow(VideoMode(1920, 1080, 32), "Small World"); 
                        // Creating credits window
                        RenderWindow creditsWindow(VideoMode(1920, 1080, 32), "Credits");

                        int x = menu.buttonPressMainMenu();
                        
                        // Start a game
                        if (x == 0) 
                        {
                            menuWindow.close();  

                            startWindow.setFramerateLimit(60);
                            Event startEvent;

                            // Creating objects
                            Player player;
                            Npc npc;
                            Portal_1 portal_1;
                            StartDialogue startDialogue;
                            DialogueCloud dialogueCloud;
                            StartBackground startBackground;


                            // ---Begin start level---
                            while (startWindow.isOpen())
                            {
                                startWindow.clear();
                                startWindow.pollEvent(startEvent); 

                                if ((startEvent.type == Event::KeyPressed && startEvent.key.code == Keyboard::Escape) || (startEvent.type == Event::Closed))
                                {
                                    isMainWindowClosed = true;
                                    startWindow.close();
                                }

                                if (isPlayerPortalCollision(player, portal_1) == true && (isDialogueWindowClosed == true))
                                {
                                    startWindow.close();
                                    break;
                                }

                                // ---Begin dialogue---
                                if ((isPlayerNpcCollision(player, npc) == true) && (isDialogueWindowClosed == false))
                                {           
                                    RenderWindow dialogueWindow(VideoMode(1920, 1080, 32), "Dialogue");  
                                    dialogueWindow.setFramerateLimit(60);

                                    DialogueCloud dialog;
                                    AbilityChoice abilityChoiceDialogue;
                                    IceBall iceBall;
                                    FireBall fireBall;
                                    LightBall lightBall;

                                    while (dialogueWindow.isOpen())
                                    {
                                        Event dialogueEvent;
                                        dialogueWindow.clear();
                                      
                                        while (dialogueWindow.pollEvent(dialogueEvent))
                                        {

                                            if (dialogueEvent.type == Event::Closed)
                                            {
                                                dialogueWindow.close();
                                                // isDialogueWindowClosed = true; // Making exception with null pointer
                                            }

                                            if (dialogueEvent.type == Event::KeyReleased)
                                            {
                                                if (dialogueEvent.key.code == Keyboard::Right)
                                                {
                                                    abilityChoiceDialogue.moveUp();
                                                    break;
                                                }
                                                if (dialogueEvent.key.code == Keyboard::Left)
                                                {
                                                    abilityChoiceDialogue.moveDown();
                                                    break;
                                                }
                                                if (dialogueEvent.key.code == Keyboard::Return)
                                                {
                                                    int choice = abilityChoiceDialogue.buttonPress();
                                                    abilityPtr = abilityChoice(choice, dialogueWindow);
                                                }
                                            }
                                        }
                                        // Dialogue window background
                                        startBackground.draw(dialogueWindow);

                                        iceBall.draw(dialogueWindow);
                                        fireBall.draw(dialogueWindow);
                                        lightBall.draw(dialogueWindow);
                                        
                                        abilityChoiceDialogue.draw(dialogueWindow);
                                        dialogueWindow.display();
                                    }

                                    // Scene after selecting ability
                                    if (isDialogueWindowClosed == true)
                                    {
                                        portal_1.changeTexture();
                                        startDialogue.text_2();
                                    }

                                    dialogueWindow.close();
                                }
                               
                                if ((abilityPtr == nullptr) && (isDialogueWindowClosed == true))
                                {
                                    Exception* exception = new Exception(1, "Ability choice error: null pointer");
                                    throw exception;
                                }

                                // Start window background
                                startBackground.draw(startWindow);
                               
                                // Player movement and appearance
                                player.update();
                                if (isDialogueWindowClosed == false) player.setBasicTexture();
                                if (isDialogueWindowClosed == true) abilityPtr->changePlayerTexture(player);
                                
                                // Rendering
                                dialogueCloud.draw(startWindow);
                                npc.draw(startWindow);
                                startDialogue.draw(startWindow);
                                player.draw(startWindow);
                                portal_1.draw(startWindow);
                                startWindow.display();
                                creditsWindow.close();
                            }

                            // ---Begin level one---
                            
                            RenderWindow firstLevelWindow(VideoMode(1920, 1080, 32), "Fight with Enemy");  
                            firstLevelWindow.setFramerateLimit(60);
                            FirstLevelBackground firstLevelBackground;

                            // enemy[0] - enemy in first level window 
                            // enemy[1] - enemy in fight window
                            Enemy enemy[2]; 

                            DefeatLyrics defeat;
                            VictoryLyrics victory;
                            Portal_2 portal_2;
                            ReadLyrics readLyrics;
                            Lava lava;
                            
                            bool isDefeatInscriptionShowed = false;
                            // Counter of player attempts
                            int attempt = 1; 
                           
                            // Writing to a file with overwriting
                            ofstream fightProcess("fightProcess.txt", ios::trunc); 

                            while (firstLevelWindow.isOpen())
                            {
                                firstLevelWindow.clear();
                                firstLevelWindow.pollEvent(startEvent); 

                                if ((startEvent.type == Event::KeyPressed && startEvent.key.code == Keyboard::Escape) || (startEvent.type == Event::Closed) || (isMainWindowClosed == true))
                                {
                                    firstLevelWindow.close();
                                }
                               
                                // ---Begin fight---
                                player.resetHealth();
                                enemy[1].resetHealth();
                                abilityPtr->disappear();
                              
                                if ((isPlayerEnemyCollision(player, enemy[0]) == true) && (isFightWindowClosed == false))
                                {
                                    RenderWindow fightWindow(VideoMode(1920, 1080, 32), "Fight"); 
                                    fightWindow.setFramerateLimit(60);
                                    FightBackground fightBackground;
                                    Dodge dodge;
                                    AttemptLyrics attemptLyrics(attempt);
                                    HealthBar healthBar;
                                    AbilityLyrics abilityLyrics(abilityPtr);
                                    // Array of objects
                                    const int numberOfFireAttackEnemy = 5;
                                    FireAttackEnemy fireAttack[numberOfFireAttackEnemy] = {}; 
                                   

                                    bool isSetAttack = false;
                                    bool isSetBack = false;
                                    bool isSetBack2 = false;
                                    bool isDodgeUsed = false;
                                    bool isAttackUsed = false;
                                    bool isMeleeAttackUsed = false;
                                    abilityPtr->isUsed = false;
                                    int finalDmg = 0;

                                    player.setToFight();

                                    fightProcess << "----------------------------------------------" << '\n' << "The challenge was taken up for the: " << attempt << " time. " << '\n';

                                    while (fightWindow.isOpen())
                                    {
                                        Event fightEvent;
                                        fightWindow.clear();
                                        fightWindow.pollEvent(fightEvent);

                                        if ((fightEvent.type == Event::KeyPressed && fightEvent.key.code == Keyboard::Escape) || (fightEvent.type == Event::Closed) || (isMainWindowClosed == true))
                                        {
                                            isDefeatInscriptionShowed = true; // Defeat after closing window
                                            player.setStartPosition();
                                            fightWindow.close();
                                        }

                                        // Ability reset
                                        if ((abilityPtr->isUsed == true) && (isDodgeUsed == true) && (isAttackUsed == true) && (isSetBack2 == true) && ((fireAttack[0].deleteFireAttack() == true) || (fireAttack[3].deleteFireAttack() == true)))
                                        {
                                            isDodgeUsed = false;
                                            abilityPtr->isUsed = false;
                                            isAttackUsed = false;
                                            isSetBack2 = false;
                                            abilityLyrics.changeColorAll();
                                        }

                                        // Handling falling fireballs (enemy's fire attacks)
                                        for (int i = 0; i < numberOfFireAttackEnemy; i++)
                                        {
                                            fireAttack[i].start();
                                            if ((fireAttack[i].deleteFireAttack() == true) && (isFightWindowClosed == false))
                                            {
                                                fireAttack[i].random = rand() % 6;
                                                fireAttack[i].setFireAttackRandom();
                                                fireAttack[i].isPlayerCollision = false;
                                            }
                                        }

                                        // Using ability
                                        if ((fightEvent.type == sf::Event::KeyPressed && fightEvent.key.code == sf::Keyboard::D) && (abilityPtr->isUsed == false))
                                        {
                                            abilityPtr->isUsed = true;
                                            abilityPtr->start(player);

                                            abilityLyrics.changeColorAbility();
                                            fightProcess << "--> Skill used: " << abilityPtr->name << '\n';
                                        }

                                        // Using dodge
                                        if ((fightEvent.type == sf::Event::KeyPressed && fightEvent.key.code == sf::Keyboard::A) && (isDodgeUsed == false))
                                        {
                                            int randomAddHealth = 0;
                                            dodge.random = rand() % 3; // Dodge in a random position
                                            player.isDodge = true;
                                            randomAddHealth = player.getHealth();
                                            player.addHealth(); // 50% chance of adding health to player
                                            isDodgeUsed = true;
                                            abilityLyrics.changeColorDodge();
                                            fightProcess << "--> Dodge used" << '\n';
                                            if (randomAddHealth != player.getHealth()) fightProcess << "and added 1 health to the player" << '\n';
                                        }

                                        // Using melee attack
                                        if ((fightEvent.type == sf::Event::KeyPressed && fightEvent.key.code == sf::Keyboard::W) && (isAttackUsed == false))
                                        {
                                            isSetBack = false;
                                            isSetAttack = true;
                                            isMeleeAttackUsed = false;

                                            isAttackUsed = true;
                                            abilityLyrics.changeColorAttack();
                                            fightProcess << "--> Melee attacked" << '\n';
                                        }
                                      
                                        // Using comeback
                                        if ((fightEvent.type == sf::Event::KeyPressed && fightEvent.key.code == sf::Keyboard::S) && (isSetBack2 == false))
                                        {
                                            isSetAttack = false;
                                            isSetBack = true;

                                            isSetBack2 = true;
                                            abilityLyrics.changeColorBack();
                                            fightProcess << "--> Player escape with his tail between his legs" << '\n';
                                        }
                                       
                                        // Taking enemy health after player's melee attack 
                                        if ((player.getUpEdge() <= enemy[1].getDownEdge()) && (isSetAttack == true) && (isMeleeAttackUsed == false))
                                        {
                                            isMeleeAttackUsed = true;
                                            takeAwayHealth(enemy[1], 1);
                                            fightProcess << " Melee attack was carried out successfully" << '\n';
                                        }

                                        // Collision between player and enemy's fire attack
                                        for (int i = 0; i < numberOfFireAttackEnemy; i++)
                                        {
                                            if ((isPlayerFireAttackEnemyCollision(player, fireAttack[i]) == true) && (fireAttack[i].isPlayerCollision == false))
                                            {
                                                takeAwayHealth(player, 1);
                                                fireAttack[i].disappear();
                                                fireAttack[i].isPlayerCollision = true;
                                                fightProcess << "--> Player didn't manage to avoid the fireball, he was left with " << player.getHealth() << " health" << '\n';
                                            }
                                        }

                                        // Collision between enemy and player's ability
                                        if (isAbilityEnemyCollision(*abilityPtr, enemy[1]) == true)
                                        {
                                            takeAwayHealth(enemy[1], 3);

                                            abilityPtr->disappear();
                                            fightProcess << "--> Enemy was hit by a " << abilityPtr->name << '\n';
                                        }
                                        for (int i = 0; i < numberOfFireAttackEnemy; i++)
                                        {
                                            // Collision between player's ability and enemy's fire attack
                                            if (isAbilityFireAttackEnemyCollision(*abilityPtr, fireAttack[i]) == true)
                                            {
                                                // Operator overloading, calculating the sum of damage after collision
                                                finalDmg = abilityPtr + fireAttack[i]; 
                                                // IceBall ability
                                                if (finalDmg > 0)
                                                {
                                                    fireAttack[i].disappear();
                                                    fightProcess << "--> As a result of the IceBall, the FireBall evaporated" << '\n';
                                                }
                                                // FireBall ability
                                                if (finalDmg < 0)
                                                {
                                                    finalDmg = finalDmg * -1;
                                                    abilityPtr->disappear();
                                                    takeAwayHealth(player, finalDmg);
                                                    fightProcess << "--> FireBall and enemy Fire attack merged and exploded\ndealing damage to the player, player was left with " << player.getHealth() << " health" << '\n';
                                                }
                                                // LightBall ability
                                                if (finalDmg == 0)
                                                {
                                                    fireAttack[i].disappear();
                                                    abilityPtr->disappear();
                                                    fightProcess << "--> Due to the interference of light waves, enemy's fire attack disappeared along with " << abilityPtr->name << '\n';
                                                }
                                            }
                                        }
                                       
                                        // When player loses all his health
                                        if (player.checkHealth() == true)
                                        {
                                            fightProcess << "--> The cute monster defeated the player during " << attempt << ". attempt!!!" << '\n' << "---------------------------------------------------------------------------------" << '\n';
                                            attempt++;
                                            fightWindow.close();
                                            isDefeatInscriptionShowed = true;
                                            player.setStartPosition();
                                        }
                                       
                                        // When enemy loses all his health
                                        if (enemy[1].checkHealth() == true)
                                        {
                                            isFightWindowClosed = true;
                                            fightWindow.close();
                                            isDefeatInscriptionShowed = false;
                                            player.setStartPosition();
                                            fightProcess << "--> Player defeated the powerful monster in just " << attempt << ". attempt!!!" << '\n' << "--------------------------------------------------------------------" << '\n';
                                        }
                                       
                                        // Health bars
                                        healthBar.updatePlayer(player);
                                        healthBar.updateEnemy(enemy[1]);

                                        // Fight window background
                                        fightBackground.draw(fightWindow);
                                        enemy[1].draw(fightWindow);
                                        fireAttack[0].draw(fightWindow);
                                        fireAttack[1].draw(fightWindow);
                                        if (fireAttack[0].isFireAttackShot == true) fireAttack[2].draw(fightWindow);
                                        if (fireAttack[1].isFireAttackShot == true) fireAttack[3].draw(fightWindow);
                                        if (fireAttack[2].isFireAttackShot == true) fireAttack[4].draw(fightWindow);

                                        healthBar.draw(fightWindow);
                                        if (abilityPtr->isAbilityFlying == true) abilityPtr->fly(fightWindow);
                                        enemy[1].changePosition();

                                        if (isFightWindowClosed == true) enemy[0].disappear();
                                        if (player.isDodge == true)  dodge.dodgeAbility(player);
                                        if (isSetAttack == true) player.setAttack();
                                        if (isSetBack == true) player.setBack();
                                        abilityLyrics.draw(fightWindow);
                                        attemptLyrics.draw(fightWindow);
                                        player.draw(fightWindow);
                                        fightWindow.display();
                                    }

                                }
                                // Reading the course of the fight from a file
                                if ((startEvent.type == sf::Event::KeyPressed && startEvent.key.code == sf::Keyboard::F) && ((isFightWindowClosed == true) || (isDefeatInscriptionShowed == true)))
                                {
                                    fightProcess.close();
                                    read();
                                }

                                if ((isPlayerPortalCollision(player, portal_2) == true) && ((isFightWindowClosed == true) || (isDefeatInscriptionShowed == true)))
                                {
                                    firstLevelWindow.close();
                                }

                                // First level window background
                                firstLevelBackground.draw(firstLevelWindow);
                                lava.draw(firstLevelWindow);
                                //Player movement
                                player.update();
                                if (isDialogueWindowClosed == true) abilityPtr->changePlayerTexture(player);
                                // Rendering
                                portal_1.draw(firstLevelWindow);
                                enemy[0].draw(firstLevelWindow);
                                // Draw text after winning
                                if ((isFightWindowClosed == true) && (isDefeatInscriptionShowed == false)) 
                                {
                                    victory.draw(firstLevelWindow);
                                    portal_2.draw(firstLevelWindow);
                                }
                                // Draw text after defeat
                                if (isDefeatInscriptionShowed == true) defeat.draw(firstLevelWindow); 
                                if ((isFightWindowClosed == true) || (isDefeatInscriptionShowed == true)) readLyrics.draw(firstLevelWindow);
                                player.draw(firstLevelWindow);
                                firstLevelWindow.display();
                            }
                            creditsWindow.close();
                            startWindow.clear();
                            startWindow.display();
                        }
                        // Open credits
                        if (x == 1)
                        {
                            Credits credits;
                            while (creditsWindow.isOpen())
                            {
                                Event creditsEvent;
                                while (creditsWindow.pollEvent(creditsEvent))
                                {
                                    if (creditsEvent.type == Event::Closed || creditsEvent.key.code == Keyboard::Escape)
                                    {
                                        creditsWindow.close();
                                    }
                                }
                              
                                startWindow.close();
                                creditsWindow.clear();
                                menuBackground.draw(creditsWindow);
                                credits.draw(creditsWindow);
                                creditsWindow.display();
                            }
                        }
                        // Exit
                        if (x == 2)
                            menuWindow.close();
                        break;
                    }
                }
            }
            menuWindow.clear();
            menuBackground.draw(menuWindow);
            menu.draw(menuWindow);
            menuWindow.display();
        }
    }
    catch (Exception* w)
    {
        errors << "Nr: " << w->getNumber() << " Description: " << w->getDescription() << '\n';
    }

    return 0;
}

