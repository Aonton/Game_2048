/* Main for game
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include "logger.h"
#include "LogModule.h"
#include "game2048.h"
#include "Menu.h"
#include "display.h"
#include "menuController.h"
#include "menuOptions.h"
#include "fileController.h"
using namespace std;
using namespace menuOpt;

// Sockets?
// add display centering
// Add more error messages
// Create Log File
// Only works for MAC OSX - TO DO: Make Windows Verison

// Optimize to print board
// Make sure screen is big enough
// Make center display class
// Move all long string displays files
string getGameOverMessage();

int main()
{
  Log log;
  log.allModuleOn();
  log.DisplayDebug();
  Display display(log);
  MenuController menuController(log);
  FileController fileController(log);
  Menu menu(log,display,menuController,fileController);
  menu.MenuLoop();
  if(menuController.getOpt()==New)
  {
    display.EndDisplay();
    Game2048 game(log,display);
    log.writeToLog(Main,"Game Starting ...\n");
    game.Start();
    game.End();
    cout<< getGameOverMessage() << endl;
    log.writeToLog(Main,"Game Ended\n");
  }
  else
  {
    display.EndDisplay();
  }
  log.allModuleOff();
}

string getGameOverMessage()
{
  return (string("***************************\n") +
          string("*                         *\n") +
          string("*         GAME OVER       *\n") +
          string("*                         *\n") +
          string("***************************\n"));
}
