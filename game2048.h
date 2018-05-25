/* Header for main game class
   Amy Feng
   5/18/2018
*/

#ifndef GAME_2048_H
#define GAME_2048_H
#include <iostream>
#include <list>
#include "board.h"
#include "userInput.h"
#include "PieceGenerator.h"
#include "collision.h"
#include "score.h"
#include "keyPress.h"
using namespace std;
using namespace keyPress;

class Game2048
{
  public:
    Game2048();

    void ClearScreen();
    void DisplayTopMenu();
    void DisplayBottomMenu(int);
    void DisplayGame(int, GameBoard);
    void Start();


  private:
    int contGame;
    list<int> pieces;
    GameBoard board;
    UserInput input;
    PieceGen piece;
    Score score;
    Collision collDetec;
    bool collision;
    bool found2048;
    bool Objective2048;
    Keys key;

    static const int end = 2048;
};

#endif
