/* Header for 2048 game board
   Amy Feng
   5/16/2018
*/
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>
#include "logger.h"
using namespace std;

class GameBoard
{
  public:
    GameBoard(int,int,int,Log&);
    GameBoard(GameBoard&);

    void PrintBoard(ostream&);
    void setPiece(int,int,int);
    int getRowSize();
    int getColSize();
    int getPiece(int,int);
    bool calFull();
    bool calEmpty();
    void boardReset();

    bool operator == (GameBoard&);
    bool operator != (GameBoard&);
    void operator = (GameBoard&);
    friend ostream& operator<< (ostream&, GameBoard&);
    friend ofstream& operator<< (ofstream&, GameBoard&);

  private:
    void PrintBar(ostream&);
    void PrintOffset(ostream&);
    void PrintSpace(ostream&);
    void PrintEmptyLine(ostream&);

    void WriteOnBoardLog(string);
    string centerText(int,string);

    const static int ROW_NUM = 4;
    const static int COL_NUM = 4;

    int board_nums [ROW_NUM][COL_NUM];
    int offset;
    int spacesBtw;
    int emptyLineNum;

    Log* logger;
};

#endif
