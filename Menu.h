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
using namespace std;

class Menu
{
  public:
    Menu(Log&, Display&, MenuController&);
    int DisplayMenu();
    void MenuLoop();
  private:
    void initMenu();
    string getFileText(string);
    string getWelcomeMessage();
    string getGame2048Icon();
    //string getTetrisIcon();
    string getMenuPageDisplay();

    void WriteOnMenu(string);
    void setOptHighlight();
    void unsetOptHighlight();
    Log* logger;
    Display* display;
    MenuController* menuController;

    Position welMenuPos;
    Position game2048MenuPos;
    Position menuPos;

    int curKey;

};

#endif
