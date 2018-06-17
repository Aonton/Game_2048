/* Main for game
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include "logger.h"
#include "GameController.h"
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
// TO DO: Replace all int, int with Pos
string getGameOverMessage();

int main()
{
  Log log;
  log.allModuleOn();
  log.DisplayDebug();
  GameController GameCtr(log);
  GameCtr.Init();
  GameCtr.Loop();
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
