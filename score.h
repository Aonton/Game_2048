/* Header for Score
   Calculates and tracks player score
   Amy Feng
   5/16/2018
*/
#ifndef SCORE_H
#define SCORE_H
#include <iostream>
using namespace std;

class Score
{
  public:
    Score();
    void addToScore(int);
    int getScore();
  private:
    int score;
};

#endif
