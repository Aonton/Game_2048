/* Header for Score
   Calculates and tracks player score
   Amy Feng
   5/16/2018
*/
#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include "logger.h"
using namespace std;

class Score
{
  public:
    Score(Log&);

    int getScore();
    void setScore(int);
    void addToScore(int);
    void scoreReset();

  private:
    void WriteOnScoreLog(string);

    int score;
    Log* logger;
};

#endif
