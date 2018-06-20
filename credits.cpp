/* Source code for
   Configuration class
   that manages the different
   options
   Amy Feng
   5/28/2018
*/

#include <iostream>
#include "credits.h"
using namespace std;

Credits::Credits(Log& log,
                 MenuController& menuCtr,
                 FileController& fileCtr,
                 Display& display)
{
  Credits::logger = &log;
  Credits::menuController = &menuCtr;
  Credits::fileController = &fileCtr;
  Credits::display = &display;
}

void Credits::setBoard()
{
  display->setBorder('C');
  display->setScreenWithStrCenteredHAtPos(5,
  fileController->getCreditsDisplay());
}

void Credits::WriteOnCreditsLog(string text)
{
  logger->writeToLog(Cred,text);
}
