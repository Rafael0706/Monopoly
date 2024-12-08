#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Constants
const int BOARD_SIZE = 10;      // Number of spaces on the board
const int STARTING_BALANCE = 1000; // Starting balance for the player
const int MAX_TURNS = 20;       // Maximum turns in the game

// Function to roll two dice
int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

// Function to move player position around the board
int movePlayer(int position, int diceRoll) {
    return (position + diceRoll) % BOARD_SIZE;
}

// Function to determine the cost or reward of landing on a space
int getPropertyEffect(int position) {
    // Simple example effects: negative for penalties, positive for rewards
    switch (position) {
    case 0: return 200;     // Collect $200 for passing start
    case 3: return -150;    // Penalty of $150
    case 5: return 100;     // Bonus of $100
    case 7: return -200;    // Penalty of $200
    case 9: return 50;      // Bonus of $50
    default: return 0;      // No effect on other spaces
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int position = 0;
    int balance = STARTING_BALANCE;
    int turn = 0;

    cout << "Welcome to Dice Monopoly!" << endl;

    // Main game loop
    while (turn < MAX_TURNS && balance > 0) {
        cout << "\nTurn " << turn + 1 << endl;
        int diceRoll = rollDice();
        cout << "You rolled a " << diceRoll << "!" << endl;

        // Move the player
        position = movePlayer(position, diceRoll);
        cout << "You landed on space " << position << "." << endl;

        // Calculate property effect
        int effect = getPropertyEffect(position);
        balance += effect;

        // Print the effect
        if (effect > 0) {
            cout << "You received a bonus of $" << effect << "!" << endl;
        }
        else if (effect < 0) {
            cout << "You paid a penalty of $" << -effect << "." << endl;
        }
        else {
            cout << "No change in balance on this space." << endl;
        }

        cout << "Your current balance is $" << balance << "." << endl;
        turn++;
    }

    // End of game
    if (balance <= 0) {
        cout << "\nGame Over! You ran out of money." << endl;
    }
    else {
        cout << "\nGame Over! You finished with $" << balance << " after " << turn << " turns." << endl;
    }

    return 0;
}
