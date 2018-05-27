/*
   Source code for PieceGen
   Number generator for the
   game board
   Amy Feng
   5/15/2018
*/

#include <iostream>
#include "PieceGenerator.h"
using namespace std;
using namespace module;

PieceGen::PieceGen(list<int> possible_num, GameBoard& board, Log& log)
{
  srand(time(NULL));

  PieceGen::possible_num = possible_num;
  PieceGen::board = &board;
  PieceGen::logger = &log;
}

int PieceGen::GeneratePiece()
{
  const int min = 1;
  const int max = 100;
  int num = (rand() % max) + min;
  int val = 0;

  // TO DO: add different settings
  if(num<=PERCENT_4S)
  {
    val = 4;
  }
  else
  {
    val = 1024;
  }

  return val;
}

Position PieceGen::GeneratePos()
{
    struct Position pos;

    pos.row = (rand() % board->getRowSize());
    pos.col = (rand() % board->getColSize());

    return pos;
}

void PieceGen::setBoard()
{
    int val = GeneratePiece();
    struct Position pos;

    if(!board->calFull())
    {
      do{
        pos = GeneratePos();
      }while(board->getPiece(pos.row,pos.col)!=0);

      board->setPiece(val,pos.row,pos.col);

      WriteOnPGLog("Piece Generated: ( " +
                   to_string(pos.row) +
                   " , " +
                   to_string(pos.col) +
                   " ) with value of " +
                   to_string(val) +
                   "\n");
    }
}

void PieceGen::WriteOnPGLog(string text)
{
  logger->writeToLog(PG,text);
}
