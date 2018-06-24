/* Menu Header File
   Controls the main
   game menu
   Amy Feng
   5/28/2018
*/

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <fstream>
#include "logger.h"
#include "display.h"
#include "position.h"
#include "menuController.h"
#include "fileController.h"
using namespace std;

class Menu
{
  public:
    Menu(Log&, Display&, MenuController&, FileController&);
    int DisplayMenu();
    void start();
    void MenuLoop();
    void endMenu();
  private:

    void WriteOnMenu(string);
    void setOptHighlight();
    void unsetOptHighlight();
    void initMenu();

    Log* logger;
    Display* display;
    MenuController* menuController;
    FileController* fileController;

    Position welMenuPos;
    Position game2048MenuPos;
    Position menuPos;

    int curKey;

};

#endif
