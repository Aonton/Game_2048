/* Source code for the
   GameBoard class
   Amy Feng
   5/15/2018
*/

#include<iostream>
#include "board.h"
using namespace std;

GameBoard::GameBoard()
{
  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      board_nums[row][col] = 0;
    }
  }
}

void GameBoard::PrintBoard()
{
  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
        cout<< board_nums[row][col] << " ";
    }

    cout<< endl;
  }

  cout<< endl;
}
