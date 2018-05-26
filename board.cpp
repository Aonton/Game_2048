/* Source code for the
   GameBoard class
   Amy Feng
   5/15/2018
*/

#include <iostream>
#include "board.h"
using namespace std;

GameBoard::GameBoard(int offset, int spacesBtw, int emptyLineNum, Log& log)
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
  GameBoard::logger = &log;
}

GameBoard::GameBoard(GameBoard& board)
{
  *this = board;
}

void GameBoard::PrintOffset(ostream& out)
{
  for(int i=0; i<GameBoard::offset; i++)
  {
    out<< " ";
  }
}

void GameBoard::PrintBar(ostream& out)
{
  PrintOffset(out);
  for(int i=0; i<=(16 + ((GameBoard::spacesBtw-1)*12)); i++)
  {
    out<< "-";
  }

  out<< endl;
}

void GameBoard::PrintSpace(ostream& out)
{
    for(int i=0; i<GameBoard::spacesBtw; i++)
    {
      out<< " ";
    }
}

void GameBoard::PrintEmptyLine(ostream& out)
{
  for(int i=0; i<GameBoard::emptyLineNum; i++)
  {
    PrintOffset(out);
    out<< "|";
    for(int j=0; j<GameBoard::COL_NUM; j++)
    {
      PrintSpace(out);
      PrintSpace(out);
      PrintSpace(out);
      out<< "|";
    }

    out<< endl;
  }

}

// Operating overload board and use different stream operator
void GameBoard::PrintBoard(ostream& out)
{
  string str;
  int length = 0;
  PrintBar(out);

  for(int row=0; row<GameBoard::ROW_NUM; row++)
  {
    PrintEmptyLine(out);
    PrintOffset(out);
    out<< "|";
    PrintSpace(out);
    for(int col=0; col<GameBoard::COL_NUM; col++)
    {
        if(board_nums[row][col] == 0)
        {
          PrintSpace(out);
        }
        else
        {
          out<< centerText(GameBoard::spacesBtw,to_string(board_nums[row][col]));
        }

        PrintSpace(out);
        out<< "|";
        PrintSpace(out);
    }

    PrintOffset(out);
    out<< endl;
    PrintEmptyLine(out);
    PrintBar(out);
  }

  out<< endl;
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
                    to_string(val));
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

    this->offset = compareBoard.offset;
    this->spacesBtw = compareBoard.spacesBtw;
    this->emptyLineNum = compareBoard.emptyLineNum;
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

void GameBoard::WriteOnBoardLog(string text)
{
  logger->writeToLog(Board,text);
}

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
    board.PrintBoard(cin);
    if(board.logger->getModuleStat(Board))
    {
      board.logger->getFileStream() << board;
    }
    return cin;
 }

ofstream& operator<<(ofstream& myfile, GameBoard& board)
{
     board.PrintBoard(myfile);
     return myfile;
}
