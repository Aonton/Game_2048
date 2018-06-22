/* Header for 2048 game board
   Amy Feng
   5/16/2018
*/
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "logger.h"
#include "fileController.h"
#include "display.h"
using namespace std;

class GameBoard
{
  public:
    GameBoard(Log&, Display& display, FileController&);
    GameBoard(GameBoard&);

    void PrintBoard();
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

    void WriteOnBoardLog(string, bool = false);
    string centerText(int,string);

    const static int ROW_NUM = 4;
    const static int COL_NUM = 4;

    int board_nums [ROW_NUM][COL_NUM];

    Log* logger;
    Display* display;
    FileController* fileCtr;
};

#endif
