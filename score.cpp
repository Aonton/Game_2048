/* Source Code for Score
   Calculates and tracks player score
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include "score.h"
using namespace std;

Score::Score()
{
  Score::score = 0;
}

int Score::getScore()
{
  return score;
}

void Score::addToScore(int points)
{
  if(points>0)
  {
    score+=points;
  }
}

void Score::scoreReset()
{
  score=0;
}

void Score::setScore(int score)
{
  if(score>=0)
  {
    Score::score = score;
  }
}
