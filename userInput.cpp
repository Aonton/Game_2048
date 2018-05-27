/* Source Code for UserInput
  Takes in the user input
  Amy Feng
  5/16/2018
*/

#include<iostream>
#include "userInput.h"
using namespace std;

UserInput::UserInput(Log& log)
{
  UserInput::logger = &log;
}

int UserInput::Input()
{
  int key = 0;

  key = getch();
  string statement = "User entered: ";

  switch(key)
  {
      case KEY_UP:
          WriteOnInputLog(statement + "UP\n");
          break;
      case KEY_DOWN:
          WriteOnInputLog(statement + "DOWN\n");
          break;
      case KEY_LEFT:
          WriteOnInputLog(statement + "LEFT\n");
          break;
      case KEY_RIGHT:
          WriteOnInputLog(statement + "RIGHT\n");
          break;
      case (int)'r':
          WriteOnInputLog(statement + "REDO\n");
          break;
      case (int)'s':
          WriteOnInputLog(statement + "RESET\n");
          break;
      case (int)'e':
          WriteOnInputLog(statement + "EXIT\n");
          break;
      case (int)'c':
          WriteOnInputLog(statement + "CONT\n");
        break;
      default:
          // Invalid key presses are fine (they are handled here)
          WriteOnInputLog(statement + " " + to_string(key) +  " (Not Valid Key Press)\n");
          return -1;
          break;
    }

    return key;
}

void UserInput::WriteOnInputLog(string text)
{
  logger->writeToLog(module::Input,text);
}
