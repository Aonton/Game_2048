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
  menu.endMenu();
  BottomBackPanel bottomPanel(*logger,
                              menuCtr,
                              fileCtr,
                              display);
  int key = 0;
  while(true)
  {
    switch(menuCtr.getOpt())
    {
      case New:
        {
          //display.EndDisplay();
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
          HighScoreBoard highScoreBoard(*logger,
                                        menuCtr,
                                        fileCtr,
                                        display);
          highScoreBoard.setBoard();
          bottomPanel.setBoard();
        }
      break;
      case Opt:
        {
          Configuration config(*logger,
                               menuCtr,
                               fileCtr,
                               display);
          config.setBoard();
          bottomPanel.setBoard();
        }
      break;
      case Creds:
        {
          Credits credits(*logger,
                          menuCtr,
                          fileCtr,
                          display);
          credits.setBoard();
          bottomPanel.setBoard();
        }
      break;
      default:
      break;
    }

    key = display.print();

    if(key == (int)'b')
    {
      display.clearScreen();
      menu.initMenu();
      menu.MenuLoop();
      menu.endMenu();
    }

    display.EndDisplay();
  }
}
