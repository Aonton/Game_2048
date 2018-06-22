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
#include <ncurses.h>
#include "board.h"
#include "userInput.h"
#include "PieceGenerator.h"
#include "collision.h"
#include "score.h"
#include "logger.h"
#include "LogModule.h"
#include "display.h"
#include "fileController.h"
#include "position.h"
using namespace std;

class Game2048
{
  public:
    Game2048(Log&, Display&, FileController&);
    void Start();
    void End();

  private:
    void ClearScreen();
    void DisplayTopMenu();
    void DisplayBottomMenu();
    void DisplayGame();
    void TimerToCont();
    void SetUpGame();
    void Win(bool&, bool&, int&);
    void Redo();
    void Reset();
    void WriteOnGameLog(string);

    string getLostMessage();

    list<int> pieces;
    GameBoard board;
    Score score;
    Collision collDetec;
    PieceGen piece;
    UserInput input;
    Log* logger;
    Display* display;
    bool showLostMessage;
    bool contGame;
    FileController* fileCtr;

    static const int end = 2048;
};

#endif
