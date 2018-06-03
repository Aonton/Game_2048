/* Source for display class
   Handles the screen
   output to the console
   Amy Feng
   6/2/2018
*/

// To Do: Catch Signal for resizing
#include <iostream>
#include "display.h"
using namespace std;

Display::Display(Log& log)
{
  Display::len = 50;
  Display::wid = 150;
  Display::max_len = 50;
  Display::max_wid = 150;
  Display::min_len = 50;
  Display::min_wid = 150;
  initscr();
  cbreak();
  start_color();
  noecho();
  /*scrollok(stdscr,true);
  idlok(stdscr,true);*/
  keypad(stdscr, true);
  cout << "\e[8;" << Display::len  << ";" << Display::wid << "t";
  initBoard();

  Display::logger = &log;
}

int Display::getScrLen()
{
  refreshScrDim();
  return len;
}

int Display::getScrWid()
{
  refreshScrDim();
  return wid;
}

void Display::refreshScrDim()
{
  int x, y;
  getmaxyx(stdscr,y,x);
  len = y;
  wid = x;
}

void Display::initBoard()
{
  display_board.resize(wid);
  for(int row = 0; row<wid; row++)
  {
    display_board[row].resize(len);
    for(int col = 0; col<len; col++)
    {
      display_board[row][col] = ' ';
    }
  }
}

void Display::WriteOnDisplay(string text)
{
  logger->writeToLog(Dis,text);
}
