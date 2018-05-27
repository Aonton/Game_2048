/* Source Code for Collision
   Detects Collision of a piece
   Resolves for collisions
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include <algorithm>
#include <list>
#include "collision.h"
using namespace std;

Collision::Collision(GameBoard& board, Score& score, const int end_num, Log& log): prevBoard(board), end(end_num)
{
  Collision::board = &board;
  Collision::score = &score;
  Collision::prevScore = 0;
  Collision::logger = &log;
}

bool Collision::NewPosition(struct Position pos, int key, bool& found2048)
{
  struct Position future_pos = pos;
  list<int> combineMarker;
  int temp_maker;
  bool collision = false;

  if(board->getPiece(pos.row,pos.col)!=0)
  {
    while(board->getPiece(future_pos.row,future_pos.col) != -1)
    {

      switch(key)
      {
        case KEY_UP:
          future_pos.row--;
        break;
        case KEY_DOWN:
          future_pos.row++;
        break;
        case KEY_LEFT:
          future_pos.col--;
        break;
        case KEY_RIGHT:
          future_pos.col++;
        break;
        default:
          WriteOnColLog("Error: Invalid Key\n");
        break;
      }

      if(key==KEY_UP || key==KEY_DOWN)
      {
        temp_maker = pos.col;
      }
      else
      {
        temp_maker = pos.row;
      }

      list<int>::iterator it;
      it = find(combineMarker.begin(), combineMarker.end(), temp_maker);

      if((board->getPiece(pos.row,pos.col) ==
         board->getPiece(future_pos.row,future_pos.col)) &&
         it == combineMarker.end())
      {
          if(board->getPiece(pos.row,pos.col) +
             board->getPiece(future_pos.row,future_pos.col) == end)
          {
            found2048 = true;
          }

          score->addToScore(board->getPiece(pos.row,pos.col) +
                              board->getPiece(future_pos.row,future_pos.col));

          board->setPiece(board->getPiece(pos.row,pos.col) +
                          board->getPiece(future_pos.row,future_pos.col),
                          future_pos.row,
                          future_pos.col
                          );
          board->setPiece(0,
                          pos.row,
                          pos.col
                          );
          // black list row/col that were already merged
          combineMarker.push_back(temp_maker);
          collision = true;
      }
      else if(board->getPiece(future_pos.row,future_pos.col) == 0)
      {
          board->setPiece(board->getPiece(pos.row,pos.col),
                          future_pos.row,
                          future_pos.col
                          );
          board->setPiece(0,
                          pos.row,
                          pos.col
                         );
          collision = true;
      }

      pos = future_pos;
    }
  }

  return collision;
}

bool Collision::shiftUp(bool& found2048)
{
  struct Position pos;
  bool collision = false;

  for(pos.row=0; pos.row<board->getRowSize(); pos.row++)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      collision = NewPosition(pos, KEY_UP, found2048) || collision;
    }
  }

  return collision;
}

bool Collision::shiftDown(bool& found2048)
{
  struct Position pos;
  bool collision = false;

  for(pos.row=board->getRowSize()-1; pos.row>=0; pos.row--)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      collision = NewPosition(pos, KEY_DOWN, found2048) || collision;
    }
  }

  return collision;
}

bool Collision::shiftRight(bool& found2048)
{
  struct Position pos;
  bool collision = false;

  for(pos.col=board->getColSize()-1; pos.col>=0; pos.col--)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      collision = NewPosition(pos, KEY_RIGHT, found2048) || collision;
    }
  }

  return collision;
}

bool Collision::shiftLeft(bool& found2048)
{
  struct Position pos;
  bool collision = false;

  for(pos.col=0; pos.col<board->getRowSize(); pos.col++)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      collision = NewPosition(pos, KEY_LEFT, found2048) || collision;
    }
  }

  return collision;
}

bool Collision::shiftAll(int key, bool& found2048)
{
  bool collision = false;
  prevBoard = *board;
  prevScore = score->getScore();

  switch(key)
  {
    case KEY_UP:
      collision = shiftUp(found2048);
    break;
    case KEY_DOWN:
      collision = shiftDown(found2048);
    break;
    case KEY_LEFT:
      collision = shiftLeft(found2048);
    break;
    case KEY_RIGHT:
      collision = shiftRight(found2048);
    break;
    default:
      WriteOnColLog("Invalid key movement\n");
    break;
  }

  WriteOnColLog((collision ? " " : "No ") + string("Possible Collision For Input\n"));
  return collision;
}

bool Collision::testShift()
{

  bool scorPrev = logger->getModuleStat(Scor);
  bool pGPrev = logger->getModuleStat(PG);
  bool boardPrev = logger->getModuleStat(Board);

  logger->moduleOff(Scor);
  logger->moduleOff(PG);
  logger->moduleOff(Board);

  bool found2048;
  GameBoard temp(*board);
  int tempScore = score->getScore();

  if(!shiftUp(found2048))
  {
    *board = temp;
    score->setScore(tempScore);
    if(!shiftDown(found2048))
    {
      *board = temp;
      score->setScore(tempScore);
      if(!shiftLeft(found2048))
      {
        *board = temp;
        score->setScore(tempScore);
        if(!shiftRight(found2048))
        {
          *board = temp;
          score->setScore(tempScore);
          return false;
        }
      }
    }
  }

  *board = temp;
  score->setScore(tempScore);

  logger->setModule(Scor,scorPrev);
  logger->setModule(PG,pGPrev);
  logger->setModule(Board,boardPrev);
  return true;
}

void Collision::UndoCollision()
{
  if(!(prevBoard.calEmpty()))
  {
    *board = prevBoard;
    score->setScore(prevScore);
  }
}

void Collision::WriteOnColLog(string text)
{
  logger->writeToLog(Col,text);
}
