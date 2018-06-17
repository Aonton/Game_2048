/* Header for high
   score class
   Amy Feng
   6/16/2018
*/

#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <iostream>
#include "menuController.h"
#include "logger.h"
#include "fileController.h"
#include "display.h"
using namespace std;

class HighScoreBoard
{
  public:
    HighScoreBoard(Log&, MenuController&, FileController&, Display&);
    void print();
  private:
    Log* logger;
    MenuController* menuController;
    FileController* fileController;
    Display* display;
};

#endif
