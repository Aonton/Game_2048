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

class UserInput
{
  public:
    UserInput();

    void DisplayTopMenu();
    void DisplayBottomMenu();
    bool Input();
    int getch(void);

  private:
    const static int KEY_UP = 65;
    const static int KEY_DOWN = 66;
    const static int KEY_LEFT = 68;
    const static int KEY_RIGHT = 67;
    const static int REDO = 114;
    const static int EXIT = 101;
};

#endif
