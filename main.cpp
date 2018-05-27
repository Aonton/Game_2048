/* Main for game
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include <list>
#include <map>
#include "logger.h"
#include "LogModule.h"
#include "game2048.h"
using namespace std;

// Sockets?
// add display centering
// Add more error messages
// Create Log File
// Only works for MAC OSX - TO DO: Make Windows Verison

// Optimize to print board
string getGameOverMessage();

int main()
{
  Log log;
  log.allModuleOn();
  //list<Module> mods;
  //mods.push_back(Main);
  //mods.push_back(Game);
  Game2048 game(log);
  log.writeToLog(Main,"Game Starting ...\n");
  game.Start();
  game.End();
  cout<< getGameOverMessage() << endl;
  log.writeToLog(Main,"Game Ended\n");
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
