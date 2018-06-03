/* Header file for
   Configuration class
   that manages the different
   options
   Amy Feng
   5/28/2018
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include<iostream>
using namespace std;

class Configuration
{
  public:
    Configuration();
    void DisplayMidGameOptions();
    void DisplayBeginGameOptions();
  private:
    int numRows;
    int numCols;
    string sizeOpt;

};
#endif
