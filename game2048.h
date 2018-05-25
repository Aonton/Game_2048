/* Header for main game class
   Amy Feng
   5/18/2018
*/

#ifndef GAME_2048_H
#define GAME_2048_H
#include <iostream>
#include <list>
#include <cstdio>
#include <ctime>
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
    void Start();

  private:
    void ClearScreen();
    void DisplayTopMenu();
    void DisplayBottomMenu();
    void DisplayGame();
    void TimerToCont();
    void SetUpGame();
    void Win(bool&, bool&);
    void Redo();
    void Reset();

    list<int> pieces;
    GameBoard board;
    Score score;
    Collision collDetec;
    PieceGen piece;
    UserInput input;

    static const int end = 2048;
};

#endif
