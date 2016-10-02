#include <iostream>
#include "../include/functions.hpp"

using namespace std;

/*
*****************

square=state of every block

*****************

states of every block:

' ' -> is blank
'X' -> p1 has put his pin in the block
'O' -> p2 has put his pin in the block

*****************
*/
char square[3][3];

GameMode gameMode;
GameState gameState;
GameResult gameResult;
ResultContainer resultContainer;

//*********************************************************



int main()
{

    initBoard(square);


    bool playing = true;
    //if the game is finished or not
    gameMode = gameInit();
    while(playing)
    {
        if(gameMode == Quit)
            break;

        playGame(gameMode,square,resultContainer);



    }

    //cin.get();
    return 0;
}
