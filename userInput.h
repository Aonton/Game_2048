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
#include <ncurses.h>
#include "logger.h"
using namespace std;

class UserInput
{
  public:
    UserInput(Log&);
    int Input();

  private:
    //int getch(void);
    void WriteOnInputLog(string);

    Log* logger;
};

#endif
