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

Display::Display(Log& log, bool color)
{
  Display::len = 46;
  Display::wid = 150;
  Display::max_len = 50;
  Display::max_wid = 150;
  Display::min_len = 50;
  Display::min_wid = 150;
  initscr();
  cbreak();
  setUserColorPrefer(color);
  /* COLOR_BLACK   0
   * COLOR_RED     1
   * COLOR_GREEN   2
   * COLOR_YELLOW  3
   * COLOR_BLUE    4
   * COLOR_MAGENTA 5
   * COLOR_CYAN    6
   * COLOR_WHITE   7
   */
  if(Display::enable_color)
  {
    start_color();
    init_pair(Green,COLOR_GREEN,COLOR_BLACK);
    attron(COLOR_PAIR(1));
  }
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

void Display::setUserColorPrefer(bool color)
{
  if(can_change_color())
  {
    if(has_colors())
    {
      Display::enable_color = color;
    }
    else
    {
      Display::enable_color = false;
    }
  }
  else
  {
    Display::enable_color = false;
  }
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
  int x = 0, y = 0;
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

int Display::print()
{
  //sortColorBlocks();
  for(int j=0; j<wid; j++)
  {
    for(int i=0; i<len; i++)
    {
      /*for(int k=0; k<colorSegments.length(); i++)
      {
        // Assumes colorSegments will never overlap
        if(colorSegments[k].pos.row == j &&
           colorSegments[k].pos.col == i)
        {
          for(int l=)
        }
      }*/

      if(display_board_highlight[j][i])
      {
          attron(A_STANDOUT);
      }
      move(i,j);
      addch(display_board[j][i]);
      attroff(A_STANDOUT);
    }
  }
  return(DisplayGetch());
}

int Display::DisplayGetch()
{
  return(getch());
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

/* Return the padding for centering the string */
int Display::setScreenWithStrCenteredHAtPos(int pos, string text)
{
  setCursorPos(pos,cursor_pos.row);
  return(setScreenWithStrCenteredH(text));
}

/* Return the padding for centering the string */
int Display::setScreenWithStrCenteredH(string text)
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

  return pad1;
}

void Display::SkipLine(int lines)
{
  cursor_pos.col+=lines;
}

void Display::setBorder(char design)
{
  for(int i=0; i<len; i++)
  {
    display_board[0][i] = design;
    display_board[wid-1][i] = design;
  }

  for(int i=1; i<wid; i++)
  {
    display_board[i][0] = design;
    display_board[i][len-1] = design;
  }

}

// clears a rectangle at a postion
void Display::clearScreenPartial(int x,int y, int rectLen, int rectWid)
{
  if( ( (rectWid <= wid) && (rectWid > 0) ) && ( (rectLen <= len) && (rectLen > 0) ) )
  {
    for(int i=x; i<rectWid+x; i++)
    {
      for(int j=y; j<rectLen+y; j++)
      {
        display_board[i][j] = ' ';
      }
    }
  }
}

void Display::clearScreenPartialCenter(int y, int rectLen, int rectWid)
{
  int diff = 0;
  int pad1 = 0;

  if(rectWid < wid)
  {
    diff = wid  - rectWid;
    pad1 = diff/2;
  }

  clearScreenPartial(pad1,y,rectLen,rectWid);

}

void Display::clearScreen()
{
  for(int i=0; i<len; i++)
  {
    for(int j=0; j<wid; j++)
    {
      display_board[j][i] = ' ';
    }
  }
  WriteOnDisplay("Screen Cleared\n");
}

void Display::clearBorder()
{
  setBorder(' ');
}

void Display::addColorSegment(ColorBlock colorBlock)
{
  colorSegments.push_back(colorBlock);
}

void Display::sortColorBlocks()
{
  if(!colorSegments.empty())
  {
    sort(colorSegments.begin(), colorSegments.end());
  }
}
