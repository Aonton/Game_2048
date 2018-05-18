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

Collision::Collision(GameBoard& board)
{
  Collision::board = &board;
}

bool Collision::NewPosition(struct Position pos, int key)
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

bool Collision::shiftUp(int key)
{
  struct Position pos;
  bool collision = false;

  for(pos.row=0; pos.row<board->getRowSize(); pos.row++)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      collision = NewPosition(pos, key) || collision;
    }
  }

  return collision;
}

bool Collision::shiftDown(int key)
{
  struct Position pos;
  bool collision = false;

  for(pos.row=board->getRowSize()-1; pos.row>=0; pos.row--)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      collision = NewPosition(pos, key) || collision;
    }
  }

  return collision;
}

bool Collision::shiftRight(int key)
{
  struct Position pos;
  bool collision = false;

  for(pos.col=board->getColSize()-1; pos.col>=0; pos.col--)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      collision = NewPosition(pos, key) || collision;
    }
  }

  return collision;
}

bool Collision::shiftLeft(int key)
{
  struct Position pos;
  bool collision = false;

  for(pos.col=0; pos.col<board->getRowSize(); pos.col++)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      collision = NewPosition(pos, key) || collision;
    }
  }

  return collision;
}

bool Collision::shiftAll(int key)
{
  bool collision = false;

  switch(key)
  {
    case KEY_UP:
      collision = shiftUp(key);
    break;
    case KEY_DOWN:
      collision = shiftDown(key);
    break;
    case KEY_LEFT:
      collision = shiftLeft(key);
    break;
    case KEY_RIGHT:
      collision = shiftRight(key);
    break;
    default:
      // empty
    break;
  }

  return collision;
}

bool Collision::testShift()
{
  GameBoard temp(*board);

  // TO DO: fix the double design later
  if(!shiftUp(KEY_UP))
  {
    *board = temp;
    if(!shiftDown(KEY_DOWN))
    {
      *board = temp;
      if(!shiftLeft(KEY_LEFT))
      {
        *board = temp;
        if(!shiftRight(KEY_RIGHT))
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
