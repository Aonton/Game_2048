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
#include "position.h"
#include "score.h"
#include "KeyPress.h"
using namespace std;
using namespace keyPress;

class Collision
{
  public:
    Collision(GameBoard&, Score&, const int);

    bool shiftAll(Keys, bool&);
    bool testShift();
    void UndoCollision();

  private:
    bool NewPosition(struct Position, Keys, bool&, bool);

    bool shiftUp(bool&, bool);
    bool shiftDown(bool&, bool);
    bool shiftLeft(bool&, bool);
    bool shiftRight(bool&, bool);

    GameBoard* board;
    GameBoard prevBoard;
    Score* score;
    int prevScore;
    const int end;

};

#endif
