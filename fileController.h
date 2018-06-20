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
    int getFileTextWid(string);
    int getFileTextMaxLenMenuDisplay();
    int getFileTextWidMenuDisplay();
    int getFileTextMaxLenWelcome();
    int getFileTextWidWelcome();
    int getFileTextMaxLenGame2048Icon();
    int getFileTextWidGame2048Icon();
    int getFileTextMaxLenBottomBackPanel();
    int getFileTextWidBottomBackPanel();

    string getWelcomeMessage();
    string getGame2048Icon();
    string getMenuPageDisplay();
    string getHighScoreDisplay();
    string getOptionDisplay();
    string getCreditsDisplay();
    string getTopScoreList();
    string getBottomBackPanel();

  private:
    void WriteOnFileLog(string);
    string getFileText(string);
    const string WELCOME_FILE;
    const string GAME2048_ICON_FILE;
    const string MENU_PAGE_FILE;
    const string HIGHSCORE_FILE;
    const string OPTION_FILE;
    const string CREDITS_FILE;
    const string TOP_SCORE_FILE;
    const string BOTTOM_BACK_PANEL_FILE;
    // TO DO: Save into a database

  Log* logger;

};

#endif
