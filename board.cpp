/* Source code for the
   GameBoard class
   Amy Feng
   5/15/2018
*/

#include<iostream>
#include "board.h"
using namespace std;

GameBoard::GameBoard(int offset, int barsPerCol)
{
  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      board_nums[row][col] = 0;
    }
  }

  GameBoard::offset = offset;
  GameBoard::barsPerCol = barsPerCol;
}

void GameBoard::PrintOffset()
{
  for(int i=0; i<GameBoard::offset; i++)
  {
    cout<< " ";
  }
}

void GameBoard::PrintBar()
{
  for(int i=0; i<=GameBoard::barsPerCol*COL_NUM; i++)
  {
    cout<< "-";
  }
}

void GameBoard::PrintBoard()
{

  PrintOffset();
  PrintBar();
  cout << endl;

  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    PrintOffset();
    cout<< "| ";
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
        if(board_nums[row][col] == 0)
        {
          cout<< " ";
        }
        else
        {
          cout<< board_nums[row][col];
        }
        cout<< " | ";
    }

    PrintOffset();
    cout<< endl;
    PrintOffset();
    PrintBar();
    cout<< endl;
  }

  cout<< endl;
}

void GameBoard::setPiece(int val, int row, int col)
{
  board_nums[row][col] = val;
}

int GameBoard::getRowSize()
{
  return ROW_NUM;
}

int GameBoard::getColSize()
{
  return COL_NUM;
}

int GameBoard::getPiece(int row, int col)
{
  return board_nums[row][col];
}
