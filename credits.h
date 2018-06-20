/* Header file for
   credits class
   Amy Feng
   6/19/2018
*/

#ifndef CREDITS_H
#define CREDITS_H
#include <iostream>
#include "menuController.h"
#include "logger.h"
#include "fileController.h"
#include "display.h"
using namespace std;

class Credits
{
  public:
    Credits(Log&,
            MenuController&,
            FileController&,
            Display&);
    void setBoard();

  private:
    void WriteOnCreditsLog(string);

    Log* logger;
    MenuController* menuController;
    FileController* fileController;
    Display* display;
};
#endif
