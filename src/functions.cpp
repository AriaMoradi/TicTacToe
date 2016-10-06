#include "../include/functions.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

GameMode doGreetings(bool success/* = false*/)
{

    system("cls\ncls");
    cout << "\n\n#################################\n\n";
    cout << "1. Player 1 Vs Player 2\n";
    cout << "2. Player 1 Vs Computer\n";
    cout << "3. End the game";
    cout << "\n\n#################################\n\n";

    if (success)
    {
        cout << "ERROR: Not a valid choice!\nPlease try again!";
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

GameMode gameInit()
{
    return doGreetings();

}

void drawBoard(char sq[3][3], ResultContainer rc)
{
    system("cls");
    char gcb = -55; //gooshe chap bala
    char o = -51; //ofoghi
    char bp = -53; // bast payeen
    char grb= -69; //gooshe rast bala
    char a = -70; //amoodi
    char br = -52; //bast rast
    char b4 = -50; // bast 4 tarafe
    char bc = -71; //bast chap
    char gcp = -56; //gooshe chap payeen
    char bb = -54; //bast bala
    char grp = -68; //gooshe rast payyeen

    char _do[4] = {o,o,o,0}; // divar ofoghi
    cout << gcb << _do << bp << _do << bp << _do << grb << endl;
    cout << a << " " << sq[0][0] << " " << a << " " << sq[0][1] << " " << a << " " << sq [0][2] << " " << a << endl;
    cout << br << _do << b4 << _do << b4 << _do << bc << endl;
    cout << a << " " << sq[1][0] << " " << a << " " << sq[1][1] << " " << a << " " << sq [1][2] << " " << a << endl;
    cout << br << _do << b4 << _do << b4 << _do << bc << endl;
    cout << a << " " << sq[2][0] << " " << a << " " << sq[2][1] << " " << a << " " << sq [2][2] << " " << a << endl;
    cout << gcp << _do << bb << _do << bb << _do << grp << endl;

    cout << "Player 1 wins Count: " << rc.p1Score << endl;
    cout << "Player 2 wins Count: " << rc.p2Score << endl;
    cout << "Number of draws : " << rc.drawCounter << endl;
}

void initBoard(char sq[3][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            sq[i][j]=' ';
}

bool gameIsFinished(char sq[3][3])
{
    //check for win
    if(sq[0][0] != ' ')
    {
        if ( sq[0][0] == sq[0][1] && sq[0][0] == sq[0][2])
            return true;
        if ( sq[0][0] == sq[1][0] && sq[0][0] == sq[2][0])
            return true;
        if ( sq[0][0] == sq[1][1] && sq[0][0] == sq[2][2])
            return true;
    }
    if(sq[2][2] != ' ')
    {
        if ( sq[2][2] == sq[2][1] && sq[2][2] == sq[2][0])
            return true;
        if ( sq[2][2] == sq[1][2] && sq[2][2] == sq[0][2])
            return true;
    }
    if(sq[0][2] != ' ' && sq[0][2] == sq[1][1] && sq[0][2] == sq[2][0] )
        return true;
    if(sq[1][1] != ' ')
    {
        if(sq[1][1] == sq[1][0] && sq[1][1] == sq[1][2])
            return true;
        if(sq[1][1] == sq[0][1] && sq[1][1] == sq[2][1])
            return true;
    }

    //check for empty block
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if ( sq[i][j]== ' ' )
                return false;
    //no one wins and board is full so the game is draw
    return true;
}

GameResult getAndUpdateGameResults(ResultContainer &resultContainer,char sq[3][3])
{
    if(sq[0][0] != ' ')
    {
        if ( sq[0][0] == sq[0][1] && sq[0][0] == sq[0][2])
        {
            if(sq[0][0]=='x')
            {
                resultContainer.p1Score++;
                return p1Win;
            }
            else
            {
                resultContainer.p2Score++;
                return p2Win;
            }
        }
        if ( sq[0][0] == sq[1][0] && sq[0][0] == sq[2][0])
        {
            if(sq[0][0]=='x')
            {
                resultContainer.p1Score++;
                return p1Win;
            }
            else
            {
                resultContainer.p2Score++;
                return p2Win;
            }
        }
        if ( sq[0][0] == sq[1][1] && sq[0][0] == sq[2][2])
        {
            if(sq[0][0]=='x')
            {
                resultContainer.p1Score++;
                return p1Win;
            }
            else
            {
                resultContainer.p2Score++;
                return p2Win;
            }
        }
    }
    if(sq[2][2] != ' ')
    {
        if ( sq[2][2] == sq[2][1] && sq[2][2] == sq[2][0])
        {
            if(sq[2][2]=='x')
            {
                resultContainer.p1Score++;
                return p1Win;
            }
            else
            {
                resultContainer.p2Score++;
                return p2Win;
            }
        }
        if ( sq[2][2] == sq[1][2] && sq[2][2] == sq[0][2])
        {
            if(sq[2][2]=='x')
            {
                resultContainer.p1Score++;
                return p1Win;
            }
            else
            {
                resultContainer.p2Score++;
                return p2Win;
            }
        }
    }
    if(sq[0][2] != ' ' && sq[0][2] == sq[1][1] && sq[0][2] == sq[2][0] )
    {
        if(sq[0][2]=='x')
        {
            resultContainer.p1Score++;
            return p1Win;
        }
        else
        {
            resultContainer.p2Score++;
            return p2Win;
        }
    }
    if(sq[1][1] != ' ')
    {
        if(sq[1][1] == sq[1][0] && sq[1][1] == sq[1][2])
        {
            if(sq[1][1]=='x')
            {
                resultContainer.p1Score++;
                return p1Win;
            }
            else
            {
                resultContainer.p2Score++;
                return p2Win;
            }
        }
        if(sq[1][1] == sq[0][1] && sq[1][1] == sq[2][1])
        {
            if(sq[1][1]=='x')
            {
                resultContainer.p1Score++;
                return p1Win;
            }
            else
            {
                resultContainer.p2Score++;
                return p2Win;
            }
        }
    }

    //because no one wins and we alredy know game is finished so result is draw
    resultContainer.drawCounter++;
    return draw;

}

vector getInput(char sq[3][3],ResultContainer rc,bool Error = false)
{
    system("cls");
    drawBoard(sq,rc);
    vector vec;

    if (Error)
    {
        cout << "Invalid input!" << endl;
    }
    cout << "Eneter x: ";
    cin >> vec.x;
    cout << "Enter y: ";
    cin >> vec.y;

    if ( !(vec.x <= 3 && vec.x >= 1 && vec.y >= 1 && vec.y <= 3) )
        return getInput(sq,rc,true);
    if ( sq[vec.x-1][vec.y-1] != ' ' )
        return getInput(sq,rc,true);

    return vec;
}

GameResult playGame(GameMode currGameMode, char sq[3][3],ResultContainer & rc)
{
    initBoard(sq);
    bool gameNotFinished = true;
    GameState turn = p1;
    int i, j;
    do
    {
        system("cls");
        drawBoard(sq,rc);



        cout << "Turn : " << (turn?"Player 2":"Player 1") << endl;
        vector vec = getInput(sq,rc);

        i = vec.x;
        j = vec.y;

        if (turn == p1)
        {
            sq[i-1][j-1] = 'x';
            turn = p2;
        }
        else
        {
            sq[i-1][j-1] = 'O';
            turn = p1;
        }
        drawBoard(sq,rc);
        if (gameIsFinished(sq))
        {
            GameResult gr = getAndUpdateGameResults(rc,sq);
            if(gr==p1Win)
            {
                cout << "Player 1 Wins!\n";
                system("pause");
                system("cls");
                return gr;
            }
            if(gr==p2Win)
            {
                cout << "Player 2 Wins!\n";
                system("pause");
                system("cls");
                return gr;
            }
            else//gr is draw
            {
                cout << "Game is draw!\n";
                system("pause");
                system("cls");
                return gr;
            }
        }

    }while(gameNotFinished);
}


