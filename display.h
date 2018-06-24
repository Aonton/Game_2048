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
//#include <list>
#include "logger.h"
#include "position.h"
#include "colorBlock.h"
using namespace std;

class Display
{
  public:
    Display(Log&,bool);
    ~Display();
    void setScreenPiece(int,int,char);
    void setScreenWithStrAtPos(int, int, string);
    void setScreenWithStr(string);
    int setScreenWithStrCenteredH(string);
    int setScreenWithStrCenteredHAtPos(int,string);
    int print();
    int DisplayGetch();
    void setCursorPos(int,int);
    void EndDisplay();
    void SkipLine(int);
    void highlightPiece(int,int);
    void unhighlightPiece(int,int);
    void setBorder(char);
    void clearScreenPartial(int,int,int,int);
    void clearScreenPartialCenter(int,int,int);
    void clearScreen();
    void clearBorder();
    void setUserColorPrefer(bool);
    void addColorSegment(ColorBlock);

    int getCursorPosX();
    int getCursorPosY();
    int getScrLen();
    int getScrWid();

  private:
    void initBoard();
    void refreshScrDim();
    void WriteOnDisplay(string);
    void sortColorBlocks();

    int len;
    int wid;
    int max_len;
    int max_wid;
    int min_len;
    int min_wid;
    bool enable_color;
    vector< vector<char> > display_board;
    vector< vector<bool> > display_board_highlight;
    Position cursor_pos;
    vector<ColorBlock> colorSegments;

    Log* logger;
};

#endif
