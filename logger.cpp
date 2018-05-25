/* Source code for logging
   Amy Feng
   5/24/2018
*/

#include <iostream>
#include "logger.h"
using namespace std;

Log::Log()
{
  pair <Module,bool> temp;
  logList.insert(make_pair(PG,false));
  logList.insert(make_pair(Board,false));
  logList.insert(make_pair(Col,false));
  logList.insert(make_pair(Game,false));
  logList.insert(make_pair(Main,false));
  logList.insert(make_pair(Scor,false));
  logList.insert(make_pair(Input,false));
}

void Log::moduleOn(Module mod)
{
  logList[mod] = true;
}

void Log::moduleOff(Module mod)
{
  logList[mod] = false;
}

void Log::writeToLog(Module mod, string text)
{
  if (logList.find(mod) != logList.end())
  {
    if(logList[mod]==true)
    {
      const time_t curTime = time(0);
      struct tm * now = localtime(&curTime);
      ofstream myfile;
      myfile.open("log.txt", std::ios_base::app);
      //myfile << asctime(localtime(&curTime)) << " - ";
      myfile << (now->tm_year + 1900) << '-'
             << (now->tm_mon + 1) << '-'
             <<  now->tm_mday << ", "
             << now->tm_hour << ":"
             << now->tm_min << ":"
             << now->tm_sec
             << " - ";

      switch(mod)
      {
        case PG:
          myfile << "PieceGenerator: ";
        break;
        case Board:
          myfile << "Board: ";
        break;
        case Col:
          myfile << "Collision: ";
        break;
        case Game:
          myfile << "Game2048: ";
          break;
        case Main:
          myfile << "Main: ";
          break;
        case Scor:
          myfile << "Score: ";
          break;
        case Input:
          myfile << "UserInput: ";
          break;
        default:
        break;
      }

      myfile << text << endl;
      myfile.close();
    }
  }
}
