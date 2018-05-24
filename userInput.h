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
#include "KeyPress.h"
using namespace std;
using namespace keyPress;

class UserInput
{
  public:
    UserInput();

    Keys Input();
    int getch(void);

  private:

};

#endif
