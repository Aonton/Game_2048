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
#define CONT 99
#define RESET 115

void ClearScreen();

// TO DO PUT MAIN INTO GAME class or display class
// add display centering
// Add more error messages
// Create Log File

void DisplayTopMenu();
void DisplayBottomMenu(int);
void DisplayGame(int, GameBoard);

// Only works for MAC OSX - TO DO: Make Windows Verison
int main()
{

  int contGame = true;
  list<int> pieces;
  pieces.push_back(2);
  pieces.push_back(4);
  // min for max game is 6 for space
  GameBoard board(10,6,2);
  UserInput input;
  PieceGen piece(pieces,board);
  Score score;
  Collision collDetec(board,score);
  bool collision = false;
  // remove later
  bool fake = false;
  bool found2048 = false;
  bool Objective2048 = true;

  int key = true;
  piece.setBoard();
  piece.setBoard();
  DisplayGame(score.getScore(),board);

  while(contGame)
  {
    key = input.Input();
    if(key!=RESET)
    {
      if(key!=REDO)
      {
        if(key!=CONT && key)
        {
          collision = collDetec.shiftAll(key, found2048);

          if(collision)
          {
            piece.setBoard();
            // DO NOT CLEAR SCREEN FIX POSITION
            // TO DO ADD COLOR
            ClearScreen();
            DisplayGame(score.getScore(),board);

            if(Objective2048)
            {
              contGame = (!found2048) && collDetec.testShift(fake);
            }
            else
            {
              contGame = collDetec.testShift(fake);
            }

            if(Objective2048 && found2048)
            {
              cout<< "YOU WIN" << endl;
              // add timer for press?
              cout<< "Press (SHIFT + C) to continue" << endl;
              key = input.Input();
              if(key==CONT)
              {
                contGame = true;
                Objective2048 = false;
              }
            }
          }
        }
      }
      else
      {
        collDetec.UndoCollision();
        DisplayGame(score.getScore(),board);
      }
    }
    else
    {
      board.boardReset();
      score.scoreReset();
      DisplayGame(score.getScore(),board);
    }
  }

  cout<< "GAME OVER" << endl;

}

void ClearScreen()
{
  cout << string( 100, '\n' );
}

void DisplayGame(int score, GameBoard board)
{
  DisplayTopMenu();
  board.PrintBoard();
  DisplayBottomMenu(score);
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
