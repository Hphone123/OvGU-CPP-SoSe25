#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define STRINGIFY(x)    #x
#define TO_STRING(x)    STRINGIFY(x)

#define WIN             true
#define LOSE            false
#define DRAW            false

#define OPTIONS         3 // Rock, Paper, Scissors

#define ROCK            1
#define PAPER           2
#define SCISSORS        3

bool matchups [OPTIONS][OPTIONS] = {
    {DRAW, LOSE, WIN },
    {WIN , DRAW, LOSE},
    {LOSE, WIN , DRAW}};

/*
 * Determines if choice1 beats choice2.
 *
 * Valid values for both parameters are:
 * 1: Rock
 * 2: Paper
 * 3: Scissors
 *
 * Rock beats Scissors, Paper beats Rock, Scissors beat Paper.
 *
 * Returns true if choice1 beats choice2
 */
bool beats(int choice1, int choice2)
{
    return matchups[choice1][choice2];
}


/*
 * Performs a game of Rock-Paper-Scissors.
 *
 * Prompts the player for a choice of Rock, Paper or Scissors (1, 2 or 3)
 * and chooses a second choice to play against.
 *
 * Displays the choice of the player and computer.
 *
 * Returns true if the player wins, false if the player loses.
 * Repeats the game in case of a draw.
 */
bool play()
{
    std::srand(std::time({}));

    std::cout << "Please enter your number (" << 
                TO_STRING(ROCK)     << " for " << STRINGIFY(ROCK)     << ", " <<
                TO_STRING(PAPER)    << " for " << STRINGIFY(PAPER)    << ", " <<
                TO_STRING(SCISSORS) << " for " << STRINGIFY(SCISSORS) << "): ";
    
    int in;
    std::cin >> in;

    std::cout << "Your enemy is thinking... \n";
    int en = (std::rand() % 3) + 1;

    std::cout << "Your enemy chose ";
    if (en == 1) std::cout << STRINGIFY(ROCK);
    if (en == 2) std::cout << STRINGIFY(PAPER);
    if (en == 3) std::cout << STRINGIFY(SCISSORS);
    std::cout << "\n";

    if (beats(in - 1, en - 1))
    {
        std::cout << "You win! Woooooooooooo!!\n";
        return true;
    }
    else
    {
        std::cout << "You loose! :(\n";
        return false;
    }
}


/*
 * Performs three games of Rock-Paper-Scissors and returns true if the player
 * wins at least two of them.
 */
bool bestOf3()
{
  if (play())

}


/*
 * Performs five games of Rock-Paper-Scissors and returns true if the player
 * wins at least three of them.
 */
bool bestOf5()
{
    // Insert your code here
}


/******************************************************************************/
// Template code starts here. Please do not edit beyond this point.
/******************************************************************************/

/*
 * Converts a game mode choice into the game mode's name for display purposes.
 *
 * Note: we can only return a raw pointer here because string literals have
 * static storage duration i.e. they survive for the whole run time of the
 * program. Returning a pointer to something that is not a string literal
 * would be dangerous!
 */
const char* gameModeToString(int mode)
{
    switch(mode){
        case 1:
            return "Single";
        case 2:
            return "Best of Three";
        case 3:
            return "Best of Five";
        default:
            return "invalid";
    }
}


int main()
{
    // Initialize random seed
    srand(time(nullptr));

    int mode = 0;
    while(true)
    {
        cout << "Choose a game mode: \n"
             << "1: " << gameModeToString(1) << "\n"
             << "2: " << gameModeToString(2) << "\n"
             << "3: " << gameModeToString(3)  << "\n"
             << "0: exit\n";
        cout << "Your choice: ";
        cin >> mode;
        if(mode == 0) return 0;
        if(mode < 1 || mode > 3)
        {
            cout << "Invalid choice\n";
            continue;
        }
        break;
    }

    bool won = false;
    switch(mode)
    {
        case 1:
            won = play();
            break;
        case 2:
            won = bestOf3();
            break;
        case 3:
            won = bestOf5();
            break;
        default:
            // unreachable code
            return -1;
    }

    if(won)
    {
        cout << "Congratulations! You win the game!\n";
    }
    else
    {
        cout << "Unfortunate! You lose the game.\n";
    }

    return 0;
}
