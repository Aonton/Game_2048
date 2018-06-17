/* Source code for
   high score class
   Amy Feng
   6/16/2018
*/

#include "highScoreBoard.h"
#include <iostream>
using namespace std;

HighScoreBoard::HighScoreBoard(Log& log,
                               MenuController& menuCtr,
                               FileController& fileCtr,
                               Display& display)
{
  HighScoreBoard::logger = &log;
  HighScoreBoard::menuController = &menuCtr;
  HighScoreBoard::fileController = &fileCtr;
  HighScoreBoard::display = &display;
}

void HighScoreBoard::print()
{
  display->setBorder('H');
  display->setScreenWithStrCenteredHAtPos(5,
    fileController->getHighScoreDisplay());
}
