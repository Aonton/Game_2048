/* Header file for UserInput
  Takes in the user input
  Amy Feng
  5/15/2018
*/

#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define REDO 114
#define EXIT 101
#define CONT 99
#define RESET 115

class UserInput
{
  public:
    UserInput();

    int Input();
    int getch(void);

  private:

};

#endif
