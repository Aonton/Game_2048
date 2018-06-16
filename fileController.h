/* Header for file
   controller class
   that has the functions
   to access file data
   Amy Feng
   5/18/2018
*/

#ifndef FILE_CTR_H
#define FILE_CTR_H
#include <iostream>
#include "logger.h"
using namespace std;

class FileController
{
  public:
    FileController(Log&);
    int getFileTextMaxLen(string);
    string getWelcomeMessage();
    string getGame2048Icon();
    string getMenuPageDisplay();

    void WriteOnFileLog(string);

  private:
    string getFileText(string);

  Log* logger;

};

#endif
