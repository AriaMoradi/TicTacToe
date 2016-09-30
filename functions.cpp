#include "functions.hpp"
#include <iostream>

using namespace std;

void printGreetings()
{
    cout << "#################################\n\n";
    cout << "1. Player 1 Vs Player 2\n";
    cout << "2. Player 1 Vs Computer\n";
    cout << "3. End the game";
    cout << "\n\n#################################";
}

void gameStart(int sucsess)
{
    printGreetings();

    int choice;
    choice = cin.get()
             //if(!(choice <= 3 && choice >= 1))
             switch(choice)
    {
    case 1:
        GameMode = PvP;
        break;

    }
}
