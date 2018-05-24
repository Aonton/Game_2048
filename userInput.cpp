/* Source Code for UserInput
  Takes in the user input
  Amy Feng
  5/16/2018
*/

#include<iostream>
#include "userInput.h"
using namespace std;

UserInput::UserInput()
{
  // EMPTY
}

Keys UserInput::Input()
{
  int input = 0;

  input = 0;
  input = getch();
  Keys key = static_cast<Keys>(input);

  switch(key)
  {
      case KEY_UP:
          //cout<< "UP" << endl;
          break;
      case KEY_DOWN:
          //cout<< "DOWN" << endl;
          break;
      case KEY_LEFT:
          //cout<< "LEFT" << endl;
          break;
      case KEY_RIGHT:
          //cout<< "RIGHT" << endl;
          break;
      case REDO:
          break;
      case RESET:
          break;
      case EXIT:
          cout<< "GAME OVER" << endl;
          exit(1);
      case CONT:
        break;
      default:
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
