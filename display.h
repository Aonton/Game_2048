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
    void setScreenWithStrCenteredHAtPos(int,string);
    int print();
    void setCursorPos(int,int);
    void EndDisplay();
    void SkipLine(int);
    void highlightPiece(int,int);
    void unhighlightPiece(int,int);
    void setBorder(char);
    void clearScreenPartial(int,int,int,int);
    void clearScreenPartialCenter(int,int,int);
    void clearScreen();

    int getCursorPosX();
    int getCursorPosY();
    int getScrLen();
    int getScrWid();

  private:
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
    vector< vector<bool> > display_board_highlight;
    Position cursor_pos;

    Log* logger;
};

#endif
