/* Header file for
   BottomBackPanel class
   that manages the display
   for the bottom panel
   of the screen (used to
   go back to the menu screen)
   Amy Feng
   6/19/2018
*/

#ifndef BOTTOM_BACK_PANEL_H
#define BOTTOM_BACK_PANEL_H
#include <iostream>
#include "menuController.h"
#include "logger.h"
#include "fileController.h"
#include "display.h"
using namespace std;

class BottomBackPanel
{
  public:
   BottomBackPanel(Log&,
                   MenuController&,
                   FileController&,
                   Display&);
  void setBoard();
  private:
    void WriteOnBBPanelLog(string);
    Log* logger;
    MenuController* menuController;
    FileController* fileController;
    Display* display;
};

#endif
