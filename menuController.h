/* Menu Controller
   Header File
   Amy Feng
   6/07/2018
*/

#ifndef MENU_CTR
#define MENU_CTR
#include <iostream>
#include <ncurses.h>
#include "logger.h"
#include "menuOptions.h"
using namespace std;
using namespace menuOpt;

class MenuController
{
  public:
    MenuController(Log&);
    void ChangeOpt(int);
    void setOpt(MenuOpt);
    MenuOpt getOpt();
    int getOptStrLen();
    int getMenuOptStart(int, int);
  private:
    void WriteOnMenuCtr(string);
    MenuOpt curOpt;
    Log* logger;


};

#endif
