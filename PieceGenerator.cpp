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

PieceGen::PieceGen(list<int> possible_num, GameBoard& board)
{
  srand(time(NULL));

  PieceGen::possible_num = possible_num;
  PieceGen::board = &board;
}

int PieceGen::GeneratePiece()
{
  const int min = 1;
  const int max = 100;
  int num = (rand() % max) + min;

  // TO DO: add different settings
  if(num<=PERCENT_4S)
  {
    return 4;
  }
  else
  {
    return 2;
  }
}

PieceGen::Position PieceGen::GeneratePos()
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
    //int count = 0; maybe here?

    // TO DO: Add end-game
    do{
      pos = GeneratePos();
    }while(board->getPiece(pos.row,pos.col)!=0);

    board->setPiece(val,pos.row,pos.col);
}