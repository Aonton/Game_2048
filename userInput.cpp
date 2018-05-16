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

void UserInput::DisplayTopMenu()
{
  cout<< "*************************" << endl;
  cout<< "*                       *" << endl;
  cout<< "*  REDO (R)   EXIT(E)   *" << endl;
  cout<< "*                       *" << endl;
  cout<< "*************************" << endl;
  cout<< endl;

}

void UserInput::DisplayBottomMenu()
{
  cout<< "*************************" << endl;
  cout<< "*         UP (^)        *" << endl;
  cout<< "*       BOTTON (v)      *" << endl;
  cout<< "*        LEFT (<-)      *" << endl;
  cout<< "*        RIGHT (->)     *" << endl;
  cout<< "*************************" << endl;
  cout<< endl;
}

bool UserInput::Input()
{
  int input = 0;
  //while(true)
  {
      input = 0;

      switch((input=getch())) {
      case KEY_UP:
          cout << endl << "Up" << endl; //key up
          break;
      case KEY_DOWN:
          cout << endl << "Down" << endl;   // key down
          break;
      case KEY_LEFT:
          cout << endl << "Left" << endl;  // key left
          break;
      case KEY_RIGHT:
          cout << endl << "Right" << endl;  // key right
          break;
      case REDO:
          cout << "REDO" << endl;
          break;
      case EXIT:
          cout<< "GAME OVER" << endl;
          exit(1);
      default:
          return false;
          break;
      }
    }

    return true;
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
