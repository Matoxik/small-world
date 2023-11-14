#include "Dodge.h"


Dodge::Dodge()
{

}

// Function to perform the dodge ability for the player during a fight
void Dodge::dodgeAbility(Player& player)
{
    
   // Check if the random value is outside the expected range [0, 2]
    if (random < 0 || random>2)
    {
        // Throw an exception if the random value is invalid
        Exception* exception = new Exception(4, "Error in randomization in the Dodge class");
        throw exception;
    }
    switch (random)
    {
    case 0:
    {
        player.dodgeRight();
    }
    break;
    case 1:
    {
        player.dodgeLeft();
    }
    break;
    case 2:
    {
        player.dodgeMiddle();
    }
    break;
    }
}
