/* Source Code file for
   BottomBackPanel class
   that manages the display
   for the bottom panel
   of the screen (used to
   go back to the menu screen)
   Amy Feng
   6/19/2018
*/

#include <iostream>
#include "BottomBackPanel.h"
using namespace std;

BottomBackPanel::BottomBackPanel(Log& log,
                                 MenuController& menuCtr,
                                 FileController& fileCtr,
                                 Display& display)
{
  BottomBackPanel::logger = &log;
  BottomBackPanel::menuController = &menuCtr;
  BottomBackPanel::fileController = &fileCtr;
  BottomBackPanel::display = &display;
}

// TO DO: 3 is hardcoded
void BottomBackPanel::setBoard()
{
  int bottomPos = display->getScrLen() -
    fileController->getFileTextMaxLenBottomBackPanel() - 3;
  display->setScreenWithStrCenteredHAtPos(bottomPos,
  fileController->getBottomBackPanel());
}

void BottomBackPanel::WriteOnBBPanelLog(string text)
{
  logger->writeToLog(BBPanel,text);
}
