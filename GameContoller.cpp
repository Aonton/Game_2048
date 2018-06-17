/* Game controller
   source code
   Controls the
   game state
   Amy Feng
   6/16/2018
*/

#include <iostream>
#include "GameController.h"
using namespace std;

GameController::GameController(Log& log):display(log),
                                         menuCtr(log),
                                         fileCtr(log),
                                         menu(log,
                                              display,
                                              menuCtr,
                                              fileCtr)
{
  GameController::logger = &log;
}

void GameController::WriteOnGameCtrLog(string text)
{
  logger->writeToLog(GameCtr,text);
}

void GameController::Init()
{
  menu.MenuLoop();
}

void GameController::Loop()
{
  switch(menuCtr.getOpt())
  {
    case New:
      {
        menu.endMenu();
        display.EndDisplay();
        Game2048 game(*logger,display);
        WriteOnGameCtrLog("Game Starting ...\n");
        game.Start();
        game.End();
        //cout<< getGameOverMessage() << endl;
        WriteOnGameCtrLog("Game Ended\n");
      }
    break;
    case HighScore:
      {
        menu.endMenu();
        HighScoreBoard highScoreBoard(*logger,
                                      menuCtr,
                                      fileCtr,
                                      display);
        highScoreBoard.print();
        display.print();
        display.EndDisplay();
      }
    break;
    default:
      display.EndDisplay();
    break;
  }
}
