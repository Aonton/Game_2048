/* Main for game
   Amy Feng
   5/16/2018
*/

#include<iostream>
#include "board.h"
#include "userInput.h"
using namespace std;

int main()
{
  GameBoard board(4,4);
  UserInput input;
  while(true)
  {
    input.DisplayTopMenu();
    board.PrintBoard();
    input.DisplayBottomMenu();
    input.Input();
    system("clear");
  }
}
