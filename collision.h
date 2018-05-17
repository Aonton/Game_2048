/* Header for Collision
   Detects Collision of a piece
   Resolves for collisions
   Amy Feng
   5/16/2018
*/

#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include "board.h"
#include "position.cpp"
using namespace std;

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67

class Collision
{
  public:
    Collision(GameBoard&);

    void NewPosition(struct Position, int);
    void shiftAll(int);

  private:
    GameBoard* board;

};

#endif