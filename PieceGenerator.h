/*
   Header for PieceGen
   Number generator for the
   game board
   Amy Feng
   5/15/2018
*/

#ifndef PIECE_GEN_H
#define PIECE_GEN_H
#include <iostream>
#include <list>
#include "board.h"
#include "position.h"
#include "logger.h"
using namespace std;

class PieceGen
{
  public:
      PieceGen(list<int>, GameBoard&, Log&);
      void setBoard();

  private:
      // TO DO: MAKE CONFIG FILE

      int GeneratePiece();
      struct Position GeneratePos();
      void WriteOnPGLog(string);

      list<int> possible_num;
      const static int PERCENT_4S = 10;
      GameBoard* board;
      Log* logger;
};

#endif
