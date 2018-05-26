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

int main()
{
  Log log;
  log.allModuleOn();
  //list<Module> mods;
  //mods.push_back(Main);
  //mods.push_back(Game);
  Game2048 game(log);
  log.writeToLog(Main,"Game Starting ...");
  game.Start();
  log.writeToLog(Main,"Game Ended");
  log.allModuleOff();
}
