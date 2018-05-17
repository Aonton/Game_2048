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

void Collision::NewPosition(struct Position pos, int key)
{
  struct Position future_pos = pos;
  list<int> combineMarker;
  int temp_maker;

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
          // empty
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
      }
      pos = future_pos;
    }
  }
}

void Collision::shiftUp(int key)
{
  struct Position pos;

  for(pos.row=0; pos.row<board->getRowSize(); pos.row++)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      NewPosition(pos, key);
    }
  }
}

void Collision::shiftDown(int key)
{
  struct Position pos;

  for(pos.row=board->getRowSize(); pos.row>=0; pos.row--)
  {
    for( pos.col=0; pos.col<board->getColSize(); pos.col++)
    {
      NewPosition(pos, key);
    }
  }
}

void Collision::shiftRight(int key)
{
  struct Position pos;

  for(pos.col=board->getColSize(); pos.col>=0; pos.col++)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      NewPosition(pos, key);
    }
  }
}

void Collision::shiftLeft(int key)
{
  struct Position pos;

  for(pos.col=0; pos.col<board->getRowSize(); pos.col++)
  {
    for(pos.row=0; pos.row<board->getColSize(); pos.row++)
    {
      NewPosition(pos, key);
    }
  }
}

void Collision::shiftAll(int key)
{

  switch(key)
  {
    case KEY_UP:
      shiftUp(key);
    break;
    case KEY_DOWN:
      shiftDown(key);
    break;
    case KEY_LEFT:
      shiftLeft(key);
    break;
    case KEY_RIGHT:
      shiftRight(key);
    break;
    default:
      // empty
    break;
  }

}
