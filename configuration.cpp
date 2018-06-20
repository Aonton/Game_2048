/* Source code for
   Configuration class
   that manages the different
   options
   Amy Feng
   5/28/2018
*/

#include <iostream>
#include "configuration.h"
using namespace std;

Configuration::Configuration(Log& log,
                             MenuController& menuCtr,
                             FileController& fileCtr,
                             Display& display)
{
  Configuration::logger = &log;
  Configuration::menuController = &menuCtr;
  Configuration::fileController = &fileCtr;
  Configuration::display = &display;
}

void Configuration::setBoard()
{
  display->setBorder('O');
  display->setScreenWithStrCenteredHAtPos(5,
  fileController->getOptionDisplay());
}

void Configuration::WriteOnConfigLog(string text)
{
  logger->writeToLog(Config,text);
}
