#include "neededVariables.hpp"

#ifndef __AI_HPP__
#define __AI_HPP__
class AI
{
public:
    char *square[3];
    int aiLevel;


    AI(char sq[3][3],int ail);
    AI(){};
    void setSquare(char sq[3][3]);
    vector choosePoint();

};


#endif
