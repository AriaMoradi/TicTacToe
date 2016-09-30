#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

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

enum GameState
{
    p1,//p1 turn
    p2,//p2 turn
    ended
};

enum GameMode
{
    PvC,//p1 vs Computer
    PvP// p1 vs p2
};


void printGreetings();

void gameStart();

#endif // __FUNCTIONS_H__
