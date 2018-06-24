/* Source code for the
   GameBoard class
   Amy Feng
   5/15/2018
*/

#include <iostream>
#include "board.h"
using namespace std;

GameBoard::GameBoard(Log& log,
                     Display& display,
                     FileController& fileCtr)
{
  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      board_nums[row][col] = 0;
    }
  }

  GameBoard::logger = &log;
  GameBoard::display = &display;
  GameBoard::fileCtr = &fileCtr;
}

GameBoard::GameBoard(GameBoard& board)
{
  *this = board;
}

void GameBoard::PrintBoard()
{
  const int fieldNum = 4;
  int boardPosRow = display->getCursorPosY();
  display->setScreenWithStr("#");
  int boardWid = fileCtr->getFileTextWidGame2048Board() - 1;
  int boardLen = fileCtr->getFileTextMaxLenGame2048Board() - 1;
  int boardPad = display->setScreenWithStrCenteredH(
    fileCtr->getGame2048BoardDisplay());
  display->setScreenWithStr("\n ");
  int cellWid = boardWid/4;
  int cellLen = boardLen/4;
  int cellLenPad = (cellLen/2) + 1;

  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      string pieceStr = " ";

      if(board_nums[row][col]!=0)
      {
        pieceStr = to_string(board_nums[row][col]);
      }

      int pieceLen = pieceStr.length();
      int diff = cellWid - pieceLen;
      if(diff>=0)
      {
        int cellWidPad = diff/2;
        display->setScreenWithStrAtPos(boardPad + cellWidPad + (cellWid*col),
                                       boardPosRow + cellLenPad + (cellLen*row),
                                       pieceStr);
      }
      else
      {
        WriteOnBoardLog("FATAL ERROR: PIECE VALUE IS IMPOSSIBLE");
      }

      WriteOnBoardLog(pieceStr + " ",false);

    }
    WriteOnBoardLog("\n",false);
  }

  // TO DO REMOVE 3
  display->setCursorPos(display->getCursorPosY()+3,display->getCursorPosX());
}

void GameBoard::setPiece(int val, int row, int col)
{
  if(row<ROW_NUM &&
     row>=0 &&
     col<COL_NUM &&
     col>=0)
  {
    board_nums[row][col] = val;

    WriteOnBoardLog("Piece ( " +
                    to_string(row) +
                    " , " +
                    to_string(col) +
                    " ) set to " +
                    to_string(val) +
                    "\n",true);
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

bool GameBoard::calEmpty()
{

  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      if(board_nums[row][col] != 0)
      {
        return false;
      }
    }
  }

  return true;
}


bool GameBoard::operator == (GameBoard& compareBoard)
{
  if(this->getRowSize() == compareBoard.getRowSize() &&
     this->getColSize() == compareBoard.getColSize())
  {
      for(int i=0; i<this->getRowSize(); i++)
      {
        for(int j=0; j<this->getColSize(); j++)
        {
          if(this->board_nums[i][j]!=compareBoard.board_nums[i][j])
          {
            return false;
          }
        }
      }
  }
  else
  {
    return false;
  }

  return true;
}

bool GameBoard::operator != (GameBoard& compareBoard)
{
  return (!(*this == compareBoard));
}

void GameBoard::operator = (GameBoard& compareBoard)
{
  if(*this != compareBoard)
  {
    if(this->getRowSize() == compareBoard.getRowSize() &&
       this->getColSize() == compareBoard.getColSize())
    {
        for(int i=0; i<this->getRowSize(); i++)
        {
          for(int j=0; j<this->getColSize(); j++)
          {
            if(this->board_nums[i][j]!=compareBoard.board_nums[i][j])
            {
              this->board_nums[i][j] = compareBoard.board_nums[i][j];
            }
          }
        }
    }
  }
}

void GameBoard::boardReset()
{
  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
      board_nums[row][col] = 0;
    }
  }
}

void GameBoard::WriteOnBoardLog(string text, bool date)
{
  logger->writeToLog(Board,text,date);
}

// To do: Don't repeat centering in main and menu
// One display class
string GameBoard::centerText(int space, string text)
{
  int length = text.length();
  if(space < length)
  {
    return text;
  }

  int diff = space  - length;
  int pad1 = diff/2;
  int pad2 = diff - pad1;
  return string(pad1,' ') + text + string(pad2,' ');
}

ostream& operator<<(ostream& cin, GameBoard& board)
{
    board.PrintBoard();

    return cin;
 }
