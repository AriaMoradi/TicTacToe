#include "../include/AI.hpp"
AI::AI(char sq[3][3],int ail) :aiLevel(ail)
{
    for(int i =0; i <3 ; i++)
        square[i] = sq[i];
}

void AI::setSquare(char sq[3][3])
{
    for(int i =0; i <3 ; i++)
        square[i] = sq[i];
}


vector AI::choosePoint()
{
    vector ch;
    if(aiLevel == 1)
    {
        for(int i = 1; i <= 3; i++)
            for(int j = 1; j <= 3; j++)
            {
                if (square[i-1][j-1] == ' ' )
                {
                    ch.x = i;
                    ch.y = j;
                    return ch;
                }
            }
    }
    if(aiLevel == 2)
    {
        //TODO
        aiLevel = 1;
        this->choosePoint();
    }

}
