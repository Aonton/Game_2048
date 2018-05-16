/* Main for game
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include <list>
#include "board.h"
#include "userInput.h"
#include "PieceGenerator.h"
using namespace std;

void ClearScreen();

int main()
{

  list<int> pieces;
  pieces.push_back(2);
  pieces.push_back(4);
  GameBoard board(4,4);
  UserInput input;
  PieceGen piece(pieces,board);

  bool is_key = true;
  input.DisplayTopMenu();
  board.PrintBoard();
  input.DisplayBottomMenu();

  while(true)
  {
    is_key = input.Input();

    if(is_key)
    {
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
