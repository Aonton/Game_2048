/* Header for 2048 game board
   Amy Feng
   5/16/2018
*/
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

class GameBoard
{
  public:
    GameBoard(int,int,int);

    void PrintBoard();
    void setPiece(int,int,int);
    int getRowSize();
    int getColSize();
    int getPiece(int,int);
    bool calFull();

  private:
    void PrintBar();
    void PrintOffset();
    void PrintSpace();
    void PrintEmptyLine();

    const static int ROW_NUM = 4;
    const static int COL_NUM = 4;

    int board_nums [ROW_NUM][COL_NUM];
    int offset;
    int spacesBtw;
    int emptyLineNum;
};

#endif
