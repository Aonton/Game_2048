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

// TO DO NOT MAKE THIS GLOBAL
// FOR NOW MAKE REDO - SCORE PREV BOARD -> GOAL only redo changed blocks
#define END 2048

Collision::Collision(GameBoard& board, Score& score): prevBoard(board)
{
  Collision::board = &board;
  Collision::score = &score;
  prevScore = 0;
}

bool Collision::NewPosition(struct Position pos, Keys key, bool& found2048, bool actualShift)
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
          cout<< "Collision::NewPosition - ERROR: INCORRECT KEY!" << endl;
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
             board->getPiece(future_pos.row,future_pos.col) == END)
          {
            found2048 = true;
          }

          if(actualShift)
          {
            score->addToScore(board->getPiece(pos.row,pos.col) +
                              board->getPiece(future_pos.row,future_pos.col));
          }

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

bool Collision::shiftUp(Keys key, bool& found2048, bool actualShift = true)
{
  struct Position pos;
  bool collision = false;

  for(pos.row=0; pos.row<board->getRowSize(); pos.row++)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      collision = NewPosition(pos, key, found2048, actualShift) || collision;
    }
  }

  return collision;
}

bool Collision::shiftDown(Keys key, bool& found2048, bool actualShift = true)
{
  struct Position pos;
  bool collision = false;

  for(pos.row=board->getRowSize()-1; pos.row>=0; pos.row--)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      collision = NewPosition(pos, key, found2048, actualShift) || collision;
    }
  }

  return collision;
}

bool Collision::shiftRight(Keys key, bool& found2048, bool actualShift = true)
{
  struct Position pos;
  bool collision = false;

  for(pos.col=board->getColSize()-1; pos.col>=0; pos.col--)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      collision = NewPosition(pos, key, found2048, actualShift) || collision;
    }
  }

  return collision;
}

bool Collision::shiftLeft(Keys key, bool& found2048, bool actualShift = true)
{
  struct Position pos;
  bool collision = false;

  for(pos.col=0; pos.col<board->getRowSize(); pos.col++)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      collision = NewPosition(pos, key, found2048, actualShift) || collision;
    }
  }

  return collision;
}

bool Collision::shiftAll(Keys key, bool& found2048)
{
  bool collision = false;
  prevBoard = *board;
  prevScore = score->getScore();

  switch(key)
  {
    case KEY_UP:
      collision = shiftUp(key, found2048);
    break;
    case KEY_DOWN:
      collision = shiftDown(key, found2048);
    break;
    case KEY_LEFT:
      collision = shiftLeft(key, found2048);
    break;
    case KEY_RIGHT:
      collision = shiftRight(key, found2048);
    break;
    default:
      // empty
    break;
  }

  return collision;
}

// DON"T WANT TEST SHIFT TO HAVE FOUND 2048
bool Collision::testShift(bool& found2048)
{
  GameBoard temp(*board);

  // TO DO: fix the double design later
  if(!shiftUp(KEY_UP, found2048, false))
  {
    *board = temp;
    if(!shiftDown(KEY_DOWN, found2048, false))
    {
      *board = temp;
      if(!shiftLeft(KEY_LEFT, found2048, false))
      {
        *board = temp;
        if(!shiftRight(KEY_RIGHT, found2048, false))
        {
          *board = temp;
          return false;
        }
      }
    }
  }

  *board = temp;
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
