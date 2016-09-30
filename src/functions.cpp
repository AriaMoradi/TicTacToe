#include "../include/functions.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

GameMode doGreetings(bool success/* = false*/)
{

    system("cls");
    cout << "\n\n#################################\n\n";
    cout << "1. Player 1 Vs Player 2\n";
    cout << "2. Player 1 Vs Computer\n";
    cout << "3. End the game";
    cout << "\n\n#################################\n\n";

    if (success)
    {
        cout << "ERROR: Not a valid choice!";
    }

    int choice;
    choice = getch() - '0';
             //if(!(choice <= 3 && choice >= 1))
    switch(choice)
    {
    case 1:
        return PvP;
        break;
    case 2:
        return PvC;
        break;
    case 3:
        return Quit;
        break;
    default:
        return doGreetings(true);
    }
}

GameMode gameStart()
{
    return doGreetings();

}
