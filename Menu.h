/* Menu Header File
   Controls the main
   game menu
   Amy Feng
   5/28/2018
*/

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "logger.h"
using namespace std;

class Menu
{
  public:
    Menu(Log&);
    void DisplayMenu();
  private:
    string CenterText(string);
    string getFileText(string);
    string getWelcomeMessage();
    string getGame2048Icon();
    //string getTetrisIcon();
    string getMenuPageDisplay();

    void WriteOnMenu(string);
    Log* logger;

};

#endif
