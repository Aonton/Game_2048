/* Source Code
   Different Input Options
   Amy Feng
   5/15/2018
*/

#include<iostream>
#include "sharedValues.h"
using namespace std;

SharedValues::SharedValues()
{
  // EMPTY
}

const int SharedValues::getUP()
{
  return KEY_UP;
}

const int SharedValues::getDOWN()
{
  return KEY_DOWN;
}

const int SharedValues::getLEFT()
{
  return KEY_LEFT;
}

const int SharedValues::getRIGHT()
{
  return KEY_RIGHT;
}

const int SharedValues::getREDO()
{
  return REDO;
}
const int SharedValues::getEXIT()
{
  return EXIT;
}
