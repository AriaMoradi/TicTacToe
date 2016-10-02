#ifndef __NEEDEDVARIABLES_HPP__
#define __NEEDEDVARIABLES_HPP__

enum GameState
{
    p1,//p1 turn
    p2,//p2 turn
    ended
};

enum GameMode
{
    PvC,//p1 vs Computer
    PvP,// p1 vs p2
    Quit
};

enum GameResult
{
    p1Win,
    p2Win,
    draw,
};

struct ResultContainer
{
    int p1Score = 0;
    int p2Score = 0;
    int drawCounter = 0;
};


#endif // __NEEDEDVARIABLES__HPP
