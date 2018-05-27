/* Header for Collision
   Detects Collision of a piece
   Resolves for collisions
   Amy Feng
   5/16/2018
*/

#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include <ncurses.h>
#include "board.h"
#include "position.h"
#include "score.h"
#include "logger.h"
using namespace std;

class Collision
{
  public:
    Collision(GameBoard&, Score&, const int, Log&);

    bool shiftAll(int, bool&);
    bool testShift();
    void UndoCollision();

  private:
    bool NewPosition(struct Position, int, bool&);

    bool shiftUp(bool&);
    bool shiftDown(bool&);
    bool shiftLeft(bool&);
    bool shiftRight(bool&);

    void WriteOnColLog(string);

    GameBoard* board;
    GameBoard prevBoard;
    Score* score;
    int prevScore;
    const int end;
    Log* logger;

};

#endif
