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
using namespace std;

// TO DO FIX THESE REPEATED VALUES
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define REDO 114
#define EXIT 101


void ClearScreen();

int main()
{

  list<int> pieces;
  pieces.push_back(2);
  pieces.push_back(4);
  GameBoard board(4,10);
  UserInput input;
  PieceGen piece(pieces,board);
  Collision collDetec(board);

  int key = true;
  input.DisplayTopMenu();
  board.PrintBoard();
  input.DisplayBottomMenu();

  while(true)
  {
    key = input.Input();

    if(key)
    {
      cout<< key << endl;
      collDetec.shiftAll(key);
      piece.setBoard();
      ClearScreen();
      input.DisplayTopMenu();
      board.PrintBoard();
      input.DisplayBottomMenu();
    }
  }
}

void ClearScreen()
{
  cout << string( 100, '\n' );
}
