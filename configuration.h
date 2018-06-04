/* Header file for
   Configuration class
   that manages the different
   options
   Amy Feng
   5/28/2018
*/

// To Do: JSON OR CSV
#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include<iostream>
using namespace std;

class Configuration
{
  public:
    Configuration();

  private:
    int boardRows;
    int boardCols;
    string sizeOpt;

    int scrlen;
    int scrwid;
    int scrmax_len;
    int scrmax_wid;
    int scrmin_len;
    int scrmin_wid;

};
#endif
