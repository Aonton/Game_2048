/* Menu Source Code
   Controls the main
   game menu
   Amy Feng
   5/28/2018
*/

#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(Log& log, Display& display, MenuController& menuController)
{
  Menu::logger = &log;
  Menu::display = &display;
  Menu::menuController = &menuController;
  Menu::welMenuPos.row = Menu::welMenuPos.col = 0;
  Menu::game2048MenuPos.row = 15;
  Menu::game2048MenuPos.col = 30;
  Menu::menuPos.row = 15;
  Menu::menuPos.col = 100;
  initMenu();
}

void Menu::initMenu()
{
  int x;
  int y;
  int space = 2;
  display->setScreenWithStrCenteredHAtPos(
  welMenuPos.row,
  getWelcomeMessage());

  display->setScreenWithStrCenteredHAtPos(
  game2048MenuPos.row,
  getGame2048Icon());

  display->setScreenWithStrAtPos(
  menuPos.col,
  menuPos.row,
  getMenuPageDisplay());

  // TO DO: REMOVE HARDCORE
  for(int i=18; i<28; i++)
  {
    display->highlightPiece(90+i,19);
  }
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

int Menu::DisplayMenu()
{
  return(display->print());
}

void Menu::MenuLoop()
{
  int key = 0;
  while(key!=10)
  {
    key = DisplayMenu();
    unsetOptHighlight();
    menuController->ChangeOpt(key);
    setOptHighlight();
  }
}

void Menu::unsetOptHighlight()
{
  // TO DO: REMOVE HARD Code
  int startCol = 90;
  int startRow = 19;
  int optLen = menuController->getOptStrLen(menuController->getOpt());
  int row = static_cast<MenuOpt> (menuController->getOpt());
  for(int i=18; i<2+optLen+18; i++)
  {
    display->unhighlightPiece(startCol+i,startRow+(row*2));
  }
}

void Menu::setOptHighlight()
{
  // TO DO: REMOVE HARD Code
  int startCol = 90;
  int startRow = 19;
  int optLen = menuController->getOptStrLen(menuController->getOpt());
  int row = static_cast<MenuOpt> (menuController->getOpt());
  for(int i=18; i<2+optLen+18; i++)
  {
    display->highlightPiece(startCol+i,startRow+(row*2));
  }
}
