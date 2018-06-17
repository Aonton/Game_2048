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

FileController::FileController(Log& log):
                              WELCOME_FILE("welcome.txt"),
                              GAME2048_ICON_FILE("game2048.txt"),
                              MENU_PAGE_FILE("menuPageDisplay.txt"),
                              HIGHSCORE_FILE("highScoreBoard.txt"),
                              OPTION_FILE("options.txt"),
                              CREDITS_FILE("credits.txt"),
                              TOP_SCORE_FILE("topScores.txt")
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
  text = text.substr(1,text.length() - 1);
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

int FileController::getFileTextWid(string file)
{
  ifstream infile;
  infile.open(file);
  string temp = "";
  int wid = 0;

  while(!infile.eof())
  {
    getline(infile,temp);

    wid++;
  }
  infile.close();
  return wid;
}

string FileController::getWelcomeMessage()
{
  return(getFileText(WELCOME_FILE));
}

string FileController::getGame2048Icon()
{
  return(getFileText(GAME2048_ICON_FILE));
}

/*string Menu::getTetrisIcon()
{
  return(getFileText("tetris.txt"));
}*/

string FileController::getMenuPageDisplay()
{
  return(getFileText(MENU_PAGE_FILE));
}

string FileController::getHighScoreDisplay()
{
  return(getFileText(HIGHSCORE_FILE));
}

string FileController::getOptionDisplay()
{
  return(getFileText(OPTION_FILE));
}

string FileController::getCreditsDisplay()
{
  return(getFileText(CREDITS_FILE));
}

string FileController::getTopScoreList()
{
  return(getFileText(TOP_SCORE_FILE));
}

void FileController::WriteOnFileLog(string text)
{
  logger->writeToLog(File,text);
}

int FileController::getFileTextMaxLenMenuDisplay()
{
  return(getFileTextMaxLen(MENU_PAGE_FILE));
}

int FileController::getFileTextWidMenuDisplay()
{
  return(getFileTextWid(MENU_PAGE_FILE));
}

int FileController::getFileTextMaxLenWelcome()
{
  return(getFileTextMaxLen(WELCOME_FILE));
}

int FileController::getFileTextWidWelcome()
{
  return(getFileTextWid(WELCOME_FILE));
}

int FileController::getFileTextMaxLenGame2048Icon()
{
  return(getFileTextMaxLen(GAME2048_ICON_FILE));
}

int FileController::getFileTextWidGame2048Icon()
{
  return(getFileTextWid(GAME2048_ICON_FILE));
}
