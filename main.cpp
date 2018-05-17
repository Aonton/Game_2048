/* Main for game
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include <list>
#include "board.h"
#include "userInput.h"
#include "PieceGenerator.h"
#include "collision.h"
#include "score.h"
using namespace std;

// Sockets?
// TO DO FIX THESE REPEATED VALUES
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define REDO 114
#define EXIT 101


void ClearScreen();

// TO DO PUT MAIN INTO GAME class or display class
// add display centering

void DisplayTopMenu();
void DisplayBottomMenu(int);

// Only works for MAC OSX - TO DO: Make Windows Verison
int main()
{

  int contGame = true;
  list<int> pieces;
  pieces.push_back(2);
  pieces.push_back(4);
  // min for max game is 6 for space
  GameBoard board(9,6,2);
  UserInput input;
  PieceGen piece(pieces,board);
  Collision collDetec(board);
  Score score;

  int key = true;
  DisplayTopMenu();
  board.PrintBoard();
  DisplayBottomMenu(score.getScore());

  while(contGame)
  {
    key = input.Input();

    if(key)
    {
      collDetec.shiftAll(key);
      contGame = piece.setBoard();
      // DO NOT CLEAR SCREEN FIX POSITION
      // TO DO ADD COLOR
      ClearScreen();
      DisplayTopMenu();
      board.PrintBoard();
      DisplayBottomMenu(score.getScore());
    }
  }

  cout<< "GAME OVER" << endl;
}

void ClearScreen()
{
  cout << string( 100, '\n' );
}

void DisplayTopMenu()
{
  cout<< "*************************************************************************************************" << endl;
  cout<< "*            *             *           *****          *            *             *              *" << endl;
  cout<< "*  REDO (R)  *  RESET (S)  *  EXIT(E)  *****  UP (^)  *  DOWN (v)  *  LEFT (<-)  *  RIGHT (->)  *" << endl;
  cout<< "*            *             *           *****          *            *             *              *" << endl;
  cout<< "*************************************************************************************************" << endl;
  cout<< endl;

}

void DisplayBottomMenu(int score)
{
  // TO DO MAKE FLEXEBLE
  // TO DO CENTER TEXT FUNCTION
  int space = 33;
  string str = to_string(score);
  int length = str.length();

  cout<< "*************************************************************************************************" << endl;
  cout<< "*              SCORE              *                                                             *" << endl;
  cout<< "*                                 *                                                             *" << endl;
  cout<< "*";

  printf ("%*s%*c",
          ((space - length) >> 1) + length,
          str.c_str(),
          ((space - length) >> 1) + ((space - length) & 1),
          ' '
        );
  cout<< "*                                                             *" << endl;
  cout<< "*                                 *                                                             *" << endl;
  cout<< "*************************************************************************************************" << endl;
  cout<< endl;
}
