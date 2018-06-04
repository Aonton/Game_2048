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

  idlok (stdscr,true);
  //scrl(stdscr,-1) to scroll down and
  //scrollok(stdscr,true) to scroll up.

  Display::cursor_pos.row = Display::cursor_pos.col = 0;
}

Display::~Display()
{
  endwin();
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

void Display::print()
{
  move(0,0);
  for(int i=0; i<len; i++)
  {
    for(int j=0; j<wid; j++)
    {
      addch(display_board[j][i]);
      logger->writeToLog(Dis,string(1,display_board[j][i]),false);
    }

    move(0,i);
  }
  getch();
}

void Display::setCursorPos(int x, int y)
{
  Display::cursor_pos.row = x;
  Display::cursor_pos.col = y;
}

void Display::setScreenWithStrAtPos(int x, int y, string str)
{
  if( ( (x < wid) && (x > 0) ) && ( (y < len) && (y > 0) ) )
  {
    for(int i = x; i<str.length(); i++)
    {
      if(str[i-x]!='\n')
      {
        setScreenPiece(y,i,str[i-x]);
      }
      else
      {
        y=y+1;
      }
    }
  }

  setCursorPos(x+1,y+1);
}

void Display::setScreenWithStr(string str)
{
  setScreenWithStrAtPos(cursor_pos.row, cursor_pos.col, str);
}

void Display::WriteOnDisplay(string text)
{
  logger->writeToLog(Dis,text);
}

void Display::setScreenPiece(int x, int y, char val)
{
  if( ( (x < wid) && (x > 0) ) && ( (y < len) && (y > 0) ) )
  {
    display_board[x][y] = val;
    setCursorPos(x+1,y+1);
  }
}
