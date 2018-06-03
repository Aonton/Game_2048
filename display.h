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
using namespace std;

class Display
{
  public:
    Display(Log&);

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

    Log* logger;
};

#endif
