#include "neededVariables.hpp"
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__


GameMode doGreetings(bool success = false);

GameMode gameInit();

void initBoard(char sq[3][3]);

void drawBoard(char sq[3][3]);

GameResult playGame(GameMode currGameMode, char sq[3][3],ResultContainer & rc);

void updateResults(GameResult gameResult, ResultContainer &resultContainer);


#endif // __FUNCTIONS_H__
