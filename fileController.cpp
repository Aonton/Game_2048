/* Source code for file
   controller class
   that has the functions
   to access file data
   Amy Feng
   6/16/2018
*/

#include<iostream>
#include "fileController.h"
using namespace std;

FileController::FileController(Log& log)
{
    FileController::logger = &log;
}

string FileController::getFileText(string file)
{
  ifstream infile;
  infile.open(file);
  string text = "";
  string temp = "";

  while(!infile.eof())
  {
    getline(infile,temp);

    text = text + '\n' + temp;
  }
  infile.close();
  return text;
}

int FileController::getFileTextMaxLen(string file)
{
  ifstream infile;
  infile.open(file);
  string temp = "";
  int len = 0;

  while(!infile.eof())
  {
    getline(infile,temp);

    if(temp.length()>len)
    {
      len = temp.length();
    }
  }
  infile.close();
  return len;
}

string FileController::getWelcomeMessage()
{
  return(getFileText("welcome.txt"));
}

string FileController::getGame2048Icon()
{
  return(getFileText("game2048.txt"));
}

/*string Menu::getTetrisIcon()
{
  return(getFileText("tetris.txt"));
}*/

string FileController::getMenuPageDisplay()
{
  return(getFileText("menuPageDisplay.txt"));
}

void FileController::WriteOnFileLog(string text)
{
  logger->writeToLog(File,text);
}
