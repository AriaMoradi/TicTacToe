#include <iostream>
#include "../include/functions.hpp"

using namespace std;

/*
*****************

square=state of every block

*****************

states of every block:

-1 -> is blank
0 -> p1 has put his pin in the block
1 -> p2 has put his pin in the block

*****************
*/
int square[9];

GameMode gameMode;
GameState gameState;


//*********************************************************



int main()
{
    for(int i=0; i<9; i++)
        square[i]=-1;

    bool playing = true;
    //if the game is finished or not
    while(playing)
    {
        gameMode = gameStart();
        if(gameMode == Quit)
            break;
    }

    //cin.get();
    return 0;
}
