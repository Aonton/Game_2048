/* Header file for logging code
   Amy Feng
   5/24/2018
*/

#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include "LogModule.h"

using namespace std;
using namespace module;

class Log
{
  public:
    Log();
    void moduleOff(Module);
    void moduleOn(Module);
    void writeToLog(Module,string);

  private:

    map<Module, bool> logList;
};

#endif
