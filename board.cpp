/* Source code for the
   GameBoard class
   Amy Feng
   5/15/2018
*/

#include <iostream>
#include "board.h"
using namespace std;

GameBoard::GameBoard(int offset, int spacesBtw, int emptyLineNum)
{
  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      board_nums[row][col] = 0;
    }
  }

  GameBoard::offset = offset;
  GameBoard::spacesBtw = spacesBtw;
  GameBoard::emptyLineNum = emptyLineNum;
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
  PrintOffset();
  for(int i=0; i<=(16 + ((GameBoard::spacesBtw-1)*12)); i++)
  {
    cout<< "-";
  }

  cout<< endl;
}

void GameBoard::PrintSpace()
{
    for(int i=0; i<GameBoard::spacesBtw; i++)
    {
      cout<< " ";
    }
}

void GameBoard::PrintEmptyLine()
{
  for(int i=0; i<GameBoard::emptyLineNum; i++)
  {
    PrintOffset();
    cout<< "|";
    for(int j=0; j<GameBoard::COL_NUM; j++)
    {
      PrintSpace();
      PrintSpace();
      PrintSpace();
      cout<< "|";
    }

    cout<< endl;
  }

}

void GameBoard::PrintBoard()
{

  PrintBar();
  PrintEmptyLine();

  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    PrintOffset();
    cout<< "|";
    PrintSpace();
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
        if(board_nums[row][col] == 0)
        {
          PrintSpace();
        }
        else
        {
          cout<< board_nums[row][col];
        }

        PrintSpace();
        cout<< "|";
        PrintSpace();
    }

    PrintOffset();
    cout<< endl;
    PrintEmptyLine();
    PrintBar();

    // TO DO: better logic
    if(row+1<GameBoard::ROW_NUM)
    {
      PrintEmptyLine();
    }
  }

  cout<< endl;
}

void GameBoard::setPiece(int val, int row, int col)
{
  if(row<ROW_NUM &&
     row>=0 &&
     col<COL_NUM &&
     col>=0)
  {
    board_nums[row][col] = val;
  }

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
  if(row>=ROW_NUM ||
     row<0 ||
     col>=COL_NUM ||
     col<0)
  {
    return -1;
  }
  return board_nums[row][col];
}

bool GameBoard::calFull()
{
  int filled_count = 0;

  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      if(board_nums[row][col] != 0)
      {
        filled_count++;
      }
    }
  }

  if(filled_count<(ROW_NUM*COL_NUM))
  {
    return false;
  }
  else
  {
    return true;
  }
}
