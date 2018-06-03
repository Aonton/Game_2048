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
#include <list>

#include "LogModule.h"

using namespace std;
using namespace module;

class Log
{
  public:
    Log();
    ~Log();
    void moduleOff(Module);
    void moduleOn(Module);
    void flipState(Module);
    void setModule(Module,bool);
    // function to write any module output to log
    void writeToLog(Module,string,bool = true);
    // function to write to log for Log Module

    void allModuleOff();
    void allModuleOn();
    void someModuleOff(list<Module>);
    void someModuleOn(list<Module>);

    // If Logger is list to turn on,
    // then it will be turned on first,
    // so that you can see the list of
    // modules be turned on
    void setSomeModules(map<Module, bool>);

    bool getModuleStat(Module);
    ofstream& getFileStream();

    void DisplayDebug();

  private:
    void WriteToLog(string);
    string getModName(Module);
    int InputDebug(int,int);
    void printDebugVal(Module);

    map<Module, bool> logList;
    ofstream myfile;
};

#endif
