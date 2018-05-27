/* Source code for logging
   Amy Feng
   5/24/2018
*/

#include <iostream>
#include "logger.h"
using namespace std;

Log::Log()
{
  myfile.open("log.txt", std::ios_base::app);

  logList.insert(make_pair(PG,false));
  logList.insert(make_pair(Board,false));
  logList.insert(make_pair(Col,false));
  logList.insert(make_pair(Game,false));
  logList.insert(make_pair(Main,false));
  logList.insert(make_pair(Scor,false));
  logList.insert(make_pair(Input,false));
  logList.insert(make_pair(Logger,false));
}

Log::~Log()
{
  myfile.close();
}

void Log::moduleOn(Module mod)
{
  logList[mod] = true;
  WriteToLog(getModName(mod) + " enabled\n");
}

void Log::moduleOff(Module mod)
{
  logList[mod] = false;
  WriteToLog(getModName(mod) + " disabled\n");
}

void Log::writeToLog(Module mod, string text, bool date)
{
  if (logList.find(mod) != logList.end())
  {
    if(logList[mod]==true)
    {
      const time_t curTime = time(0);
      struct tm * now = localtime(&curTime);

      if(date)
      {
        myfile << (now->tm_year + 1900) << '-'
               << (now->tm_mon + 1) << '-'
               <<  now->tm_mday << ", "
               << now->tm_hour << ":"
               << now->tm_min << ":"
               << now->tm_sec
               << " - "
               << getModName(mod)
               << ": ";
      }

      myfile << text;
    }
  }
}

void Log::flipState(Module mod)
{
  logList[mod] = !logList[mod];
  WriteToLog(getModName(mod) +
             (logList[mod] ? " enabled\n" : " disabled\n"));
}

void Log::setModule(Module mod, bool enable)
{
  logList[mod] = enable;
  WriteToLog(getModName(mod) +
             (logList[mod] ? " enabled\n" : " disabled\n"));
}

void Log::WriteToLog(string text)
{
  writeToLog(Logger, text);
}

string Log::getModName(Module mod)
{
  string modName = "";

  switch(mod)
  {
    case PG:
      modName = "PieceGenerator";
    break;
    case Board:
      modName = "Board";
    break;
    case Col:
      modName = "Collision";
    break;
    case Game:
      modName = "Game2048";
      break;
    case Main:
      modName = "Main";
      break;
    case Scor:
      modName = "Score";
      break;
    case Input:
      modName = "UserInput";
      break;
    case Logger:
      modName = "Logger";
      break;
    default:
      WriteToLog("Error: No Logger Module Name for this input");
    break;
  }

  return modName;
}

void Log::allModuleOff()
{
    map<Module, bool>::iterator it;

    for ( it = logList.begin(); it != logList.end(); it++ )
    {
        logList[it->first] = false;
    }

    WriteToLog("All logs disabled\n");
}

void Log::allModuleOn()
{
  map<Module, bool>::iterator it;

  for ( it = logList.begin(); it != logList.end(); it++ )
  {
      logList[it->first] = true;
  }

  WriteToLog("All logs enabled\n");
}

void Log::someModuleOff(list<Module> mods)
{
  list<Module>::iterator it;

  for ( it = mods.begin(); it != mods.end(); it++ )
  {
    moduleOff(*it);
  }
}

void Log::someModuleOn(list<Module> mods)
{
  list<Module>::iterator it;

  for ( it = mods.begin(); it != mods.end(); it++ )
  {
    moduleOn(*it);
  }
}

void Log::setSomeModules(map<Module, bool> setModule)
{
  map<Module, bool>::iterator it;
  it = setModule.find(Logger);
  if (it != setModule.end())
  {
    if(setModule[Logger] == true)
    {
      moduleOn(Logger);
      setModule.erase(it);
    }
  }

  for ( it = setModule.begin(); it != setModule.end(); it++ )
  {
      logList[it->first] = it->second;
      WriteToLog(getModName(it->first) +
                 (it->second ? " enabled\n" : " disabled\n"));
  }
}

bool Log::getModuleStat(Module mod)
{
  return logList[mod];
}

ofstream& Log::getFileStream()
{
  return myfile;
}
