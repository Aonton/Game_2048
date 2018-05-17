/* Header File
   Different Input Options
   Amy Feng
   5/15/2018
*/

#ifndef SHARED_VALUES_H
#define SHARED_VALUES_H
#include<iostream>
using namespace std;

class SharedValues
{
  public:
    SharedValues();
    const int getUP();
    const int getDOWN();
    const int getLEFT();
    const int getRIGHT();
    const int getREDO();
    const int getEXIT();

  private:
    const static int KEY_UP = 65;
    const static int KEY_DOWN = 66;
    const static int KEY_LEFT = 68;
    const static int KEY_RIGHT = 67;
    const static int REDO = 114;
    const static int EXIT = 101;

};

#endif
