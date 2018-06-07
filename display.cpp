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

void Display::highlightPiece(int x, int y)
{
  display_board_highlight[x][y] = true;
}

void Display::unhighlightPiece(int x, int y)
{
  display_board_highlight[x][y] = false;
}


void Display::EndDisplay()
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
  display_board_highlight.resize(wid);
  for(int row = 0; row<wid; row++)
  {
    display_board[row].resize(len);
    display_board_highlight[row].resize(len);
    for(int col = 0; col<len; col++)
    {
      display_board_highlight[row][col] = false;
      display_board[row][col] = ' ';
    }
  }
}

void Display::print()
{
  for(int i=0; i<len; i++)
  {
    for(int j=0; j<wid; j++)
    {
      //addch(display_board[j][i]);
      //printw(&display_board[j][i]);

      if(display_board_highlight[j][i])
      {
          attron(A_STANDOUT);
      }
      move(i,j);
      addch(display_board[j][i]);
      attroff(A_STANDOUT);
      //logger->writeToLog(Dis,string(1,display_board[j][i]),false);
    }
  }

  getch();
}

void Display::setCursorPos(int x, int y)
{
  Display::cursor_pos.row = y;
  Display::cursor_pos.col = x;
}

void Display::setScreenWithStrAtPos(int x, int y, string str)
{
  if( ( (x < wid) && (x >= 0) ) && ( (y < len) && (y >= 0) ) )
  {
    int row = x;
    for(int i = x; i<str.length()+x; i++)
    {
      if(str[i-x]!='\n')
      {
        setScreenPiece(y,row,str[i-x]);
      }
      else
      {
          y=y+1;
          row=x-1;
      }
      row++;
    }
  }
  else
  {
    WriteOnDisplay("Error: Can't print off screen\n");
  }
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
  if( ( (y < wid) && (y >= 0) ) && ( (x < len) && (x >= 0) ) )
  {
    display_board[y][x] = val;
    if( (y+1) < wid)
    {
      setCursorPos(x,y+1);
    }
    else if ( (x+1) < len )
    {
      setCursorPos(x+1,0);
    }
    else
    {
      WriteOnDisplay("Cursor Tried To Move Out Of Frame\n");
    }
  }
}

int Display::getCursorPosX()
{
  return cursor_pos.row;
}

int Display::getCursorPosY()
{
  return cursor_pos.col;
}

void Display:: setScreenWithStrCenteredH(string text)
{
  int length = 0;
  int diff = 0;
  int pad1 = 0;
  int pos = 0;
  string token = "*";
  string delimiter = "\n";

  while((pos = text.find(delimiter)) != string::npos)
  {
    token = text.substr(0,pos);
    if(token!="")
    {
      length = token.length();

      if(wid < length)
      {
        setScreenWithStrAtPos(pad1,cursor_pos.col+1,token);
      }

      diff = wid  - length;
      pad1 = diff/2;

      setScreenWithStrAtPos(pad1,cursor_pos.col+1,token);
    }
    text.erase(0, pos + delimiter.length());
  }
}

void Display::SkipLine(int lines)
{
  cursor_pos.col+=lines;
}
