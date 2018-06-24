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
  bool cont = true;
  menu.endMenu();
  BottomBackPanel bottomPanel(*logger,
                              menuCtr,
                              fileCtr,
                              display);
  int key = 0;
  while(cont)
  {
    switch(menuCtr.getOpt())
    {
      case New:
        {
          Game2048 game(*logger,display,fileCtr);
          WriteOnGameCtrLog("Game Starting ...\n");
          game.Start();
          display.clearScreen();
          menu.start();
          if(menuCtr.getOpt()==Exit)
          {
            cont = false;
          }
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
      case Exit:
        cont = false;
      break;
      default:
      break;
    }

    if(cont)
    {
      if(menuCtr.getOpt()!=New)
      {
        key = display.print();
      }

      if(key == (int)'b')
      {
        display.clearScreen();
        menu.start();
      }
    }
  }
  display.EndDisplay();
}
