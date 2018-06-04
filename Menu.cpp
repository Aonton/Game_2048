/* Menu Source Code
   Controls the main
   game menu
   Amy Feng
   5/28/2018
*/

#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(Log& log, Display& display)
{
  Menu::logger = &log;
  Menu::display = &display;
}

void Menu::setMenu()
{
  int x, y;

  display->setScreenWithStrAtPos(0,0,getWelcomeMessage());
  display->setScreenWithStr(getGame2048Icon());
  display->setScreenWithStr(getMenuPageDisplay());
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
