/* Menu Controller
   Source Code
   Amy Feng
   6/07/2018
*/

#include <iostream>
#include "menuController.h"
using namespace std;

MenuController::MenuController(Log& log)
{
  MenuController::logger = &log;
  MenuController::curOpt = New;
}

void MenuController::WriteOnMenuCtr(string text)
{
  logger->writeToLog(MenCtr,text);
}

void MenuController::ChangeOpt(int key)
{
  switch(curOpt)
  {
    case New:
      if(key==KEY_DOWN)
      {
        curOpt = Cont;
      }
      break;
    case Cont:
      if(key==KEY_UP)
      {
        curOpt = New;
      }
      else if(key==KEY_DOWN)
      {
        curOpt = HighScore;
      }
      break;
    case HighScore:
      if(key==KEY_UP)
      {
        curOpt = Cont;
      }
      else if(key==KEY_DOWN)
      {
        curOpt = Opt;
      }
      break;
    case Opt:
      if(key==KEY_UP)
      {
        curOpt = HighScore;
      }
      else if(key==KEY_DOWN)
      {
        curOpt = Credits;
      }
      break;
    case Credits:
      if(key==KEY_UP)
      {
        curOpt = Opt;
      }
      else if(key==KEY_DOWN)
      {
        curOpt = Exit;
      }
      break;
    case Exit:
      if(key==KEY_UP)
      {
        curOpt = Credits;
      }
      break;
    default:
      break;
  }
}

MenuOpt MenuController::getOpt()
{
  return curOpt;
}

int MenuController::getOptStrLen()
{
  switch(curOpt)
  {
    case New:
      return(8);
      break;
    case Cont:
      return(13);
      break;
    case HighScore:
      return(15);
      break;
    case Opt:
    case Credits:
      return(7);
      break;
    case Exit:
      return(4);
      break;
    default:
      break;
  }
}

int MenuController::getMenuOptStart(int menuLen, int optLen)
{
  int diff = menuLen  - optLen;
  int pad1 = diff/2;
  return pad1;
}
