/* Source Code for Collision
   Detects Collision of a piece
   Resolves for collisions
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include "collision.h"
using namespace std;

Collision::Collision(GameBoard& board)
{
  Collision::board = &board;
}

void Collision::NewPosition(struct Position pos, int key)
{
  struct Position future_pos = pos;

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

      if((future_pos.row == 0 ||
         future_pos.row == board->getRowSize() ||
         future_pos.col == 0 ||
         future_pos.col == board->getColSize()) &&
         board->getPiece(pos.row,pos.col) ==
         board->getPiece(future_pos.row,future_pos.col))
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

void Collision::shiftAll(int key)
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
