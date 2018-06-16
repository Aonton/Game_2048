/* Menu Source Code
   Controls the main
   game menu
   Amy Feng
   5/28/2018
*/

#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(Log& log,
           Display& display,
           MenuController& menuController,
           FileController& fileController
           )
{
  Menu::logger = &log;
  Menu::display = &display;
  Menu::menuController = &menuController;
  Menu::fileController = &fileController;
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
  fileController->getWelcomeMessage());

  display->setScreenWithStrCenteredHAtPos(
  game2048MenuPos.row,
  fileController->getGame2048Icon());

  display->setScreenWithStrAtPos(
  menuPos.col,
  menuPos.row,
  fileController->getMenuPageDisplay());

  // TO DO: REMOVE HARDCORE
  for(int i=18; i<28; i++)
  {
    display->highlightPiece(90+i,19);
  }
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
  int startRow = 19;
  int optLen = menuController->getOptStrLen();
  int startCol = 81 + menuController->getMenuOptStart(
    fileController->getFileTextMaxLen("menuPageDisplay.txt"),optLen);
  int row = static_cast<MenuOpt> (menuController->getOpt());
  for(int i=18; i<2+optLen+18; i++)
  {
    display->unhighlightPiece(startCol+i,startRow+(row*2));
  }
}

void Menu::setOptHighlight()
{
  // TO DO: REMOVE HARD Code
  int startRow = 19;
  int optLen = menuController->getOptStrLen();
  int startCol = 81 + menuController->getMenuOptStart(
    fileController->getFileTextMaxLen("menuPageDisplay.txt"),optLen);
  int row = static_cast<MenuOpt> (menuController->getOpt());
  for(int i=18; i<2+optLen+18; i++)
  {
    display->highlightPiece(startCol+i,startRow+(row*2));
  }
}
