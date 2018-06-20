/* Game controller
   Header File
   Controls the
   game state
   Amy Feng
   6/16/2018
*/

#ifndef GAME_CTR_H
#define GAME_CTR_H
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
#include "highScoreBoard.h"
#include "configuration.h"
#include "credits.h"
#include "BottomBackPanel.h"
using namespace std;
using namespace menuOpt;

class GameController
{
  public:
    GameController(Log&);
    void Init();
    void Loop();
  private:
    void WriteOnGameCtrLog(string);
    Log* logger;
    Display display;
    MenuController menuCtr;
    FileController fileCtr;
    Menu menu;
};

#endif
