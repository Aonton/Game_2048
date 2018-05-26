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

Keys UserInput::Input()
{
  int input = 0;

  input = 0;
  input = getch();
  Keys key = static_cast<Keys>(input);
  string statement = "User entered: ";

  switch(key)
  {
      case KEY_UP:
          WriteOnInputLog(statement + "UP");
          break;
      case KEY_DOWN:
          WriteOnInputLog(statement + "DOWN");
          break;
      case KEY_LEFT:
          WriteOnInputLog(statement + "LEFT");
          break;
      case KEY_RIGHT:
          WriteOnInputLog(statement + "RIGHT");
          break;
      case REDO:
          WriteOnInputLog(statement + "REDO");
          break;
      case RESET:
          WriteOnInputLog(statement + "RESET");
          break;
      case EXIT:
          WriteOnInputLog(statement + "EXIT");
          cout<< "GAME OVER" << endl;
          exit(1);
      case CONT:
          WriteOnInputLog(statement + "CONT");
        break;
      default:
          // TO DO: multi invalid keys
          WriteOnInputLog(statement + "? (Not Valid Key Preess)");
          return OTHER;
          break;
    }

    return key;
}

int UserInput::getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void UserInput::WriteOnInputLog(string text)
{
  // To do: think about the namespace
  logger->writeToLog(module::Input,text);
}
