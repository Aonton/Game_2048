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
  int x;
  int y;
  int space = 2;
  display->setScreenWithStrCenteredH(getWelcomeMessage());
  y = display->getCursorPosY();
  display->SkipLine(space);

  display->setScreenWithStrCenteredH(getGame2048Icon());
  x = display->getCursorPosX();

  display->setScreenWithStrAtPos(x+10,y+space,getMenuPageDisplay());
  display->setCursorPos(x+4,y+9);
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

string Menu::getFileText(string file)
{
  ifstream infile;
  infile.open(file);
  string text = "";
  string temp = "";

  while(!infile.eof())
  {
    getline(infile,temp);

    text = text + '\n' + temp;
  }
  infile.close();
  return text;
}

void Menu::WriteOnMenu(string text)
{
  logger->writeToLog(Men,text);
}
