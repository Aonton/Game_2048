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
using namespace std;

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define REDO 114
#define EXIT 101
#define CONT 99
#define RESET 115

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
    bool fake;
    bool found2048;
    bool Objective2048;
    int key;
};

#endif 
