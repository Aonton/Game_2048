/* Menu Source Code
   Controls the main
   game menu
   Amy Feng
   5/28/2018
*/

#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(Log& log)
{
  Menu::logger = &log;
  initscr();
  cbreak();
  start_color();
  noecho();
  /*scrollok(stdscr,true);
  idlok(stdscr,true);*/
  keypad(stdscr, true);
}

void Menu::DisplayMenu()
{
  WINDOW* win = newwin(20,20,0,0);
  //wclear(win);
  //wrefresh(win);
  int x, y;

  // TO DO REMOVE (hardcord)
  // TO DO FIX ERROR
  // Combine fines
  mvprintw(0,0,"%s",getWelcomeMessage().c_str());
  //getyx(stdscr,y,x);
  printw("%s",getGame2048Icon().c_str());

  printw("%s\n\n",getMenuPageDisplay().c_str());
  //printw("%d %d", x, y);
  //move(17,37);
  //mvprintw(17,37,"%s\n\n",getTetrisIcon().c_str());
  getch();
  endwin();
}

string Menu::CenterText(string text)
{
  int x, y;
  int length = text.length();
  getmaxyx(stdscr,y,x);

  if(x < length)
  {
    return text;
  }

  int diff = x  - length;
  int pad1 = diff/2;
  int pad2 = diff - pad1;
  return string(pad1,' ') + text + string(pad2,' ');
}

string Menu::getWelcomeMessage()
{
  return(getFileText("welcome.txt"));
}

string Menu::getGame2048Icon()
{
  return(getFileText("game2048.txt"));
}

/*string Menu::getTetrisIcon()
{
  return(getFileText("tetris.txt"));
}*/

string Menu::getMenuPageDisplay()
{
  return(getFileText("menuPageDisplay.txt"));
}

// The text returned will always be centered
string Menu::getFileText(string file)
{
  string text = "";
  string temp;
  ifstream infile;
  infile.open(file);
  while(!infile.eof())
  {
    getline(infile,temp);
    temp = CenterText(temp);
    text = text + temp;
  }
  infile.close();
  return text;
}

void Menu::WriteOnMenu(string text)
{
  logger->writeToLog(Men,text);
}
