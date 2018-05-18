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
#include "score.h"
using namespace std;

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67

class Collision
{
  public:
    Collision(GameBoard&, Score&);

    bool shiftAll(int, bool&);
    bool testShift(bool&);
    void UndoCollision();

  private:
    bool NewPosition(struct Position, int, bool&, bool);

    bool shiftUp(int, bool&, bool);
    bool shiftDown(int, bool&, bool);
    bool shiftLeft(int, bool&, bool);
    bool shiftRight(int, bool&, bool);

    GameBoard* board;
    GameBoard prevBoard;
    Score* score;
    int prevScore;

};

#endif
