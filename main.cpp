/* Main for game
   Amy Feng
   5/16/2018
*/

#include <iostream>
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
  // To do how to make this not as big and repettive
  //log.moduleOn(Main);
  //log.moduleOn(Game);
  //log.moduleOn(PG);
  //log.moduleOn(Board);
  log.moduleOn(Col);
  log.moduleOn(Scor);
  log.moduleOn(Input);
  Game2048 game(log);
  log.writeToLog(Main,"Game Starting ...");
  game.Start();
  log.writeToLog(Main,"Game Ended");
}
