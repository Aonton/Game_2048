/* Header for display class
   Handles the screen
   output to the console
   Amy Feng
   6/2/2018
*/

#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <ncurses.h>
#include <vector>
#include "logger.h"
#include "position.h"
using namespace std;

class Display
{
  public:
    Display(Log&);
    ~Display();
    void setScreenPiece(int,int,char);
    void setScreenWithStrAtPos(int, int, string);
    void setScreenWithStr(string);
    void setScreenWithStrCenteredH(string);
    void print();
    void setCursorPos(int,int);
    void EndDisplay();
    void SkipLine(int);

    int getCursorPosX();
    int getCursorPosY();

  private:
    int getScrLen();
    int getScrWid();
    void initBoard();
    void refreshScrDim();
    void WriteOnDisplay(string);

    int len;
    int wid;
    int max_len;
    int max_wid;
    int min_len;
    int min_wid;
    vector< vector<char> > display_board;
    Position cursor_pos;

    Log* logger;
};

#endif
