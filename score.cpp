/* Source Code for Score
   Calculates and tracks player score
   Amy Feng
   5/16/2018
*/

#include <iostream>
#include "score.h"
using namespace std;

Score::Score(Log& log)
{
  Score::score = 0;
  Score::logger = &log;
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
    /*WriteOnScoreLog("Points added to score: " +
                    to_string(points) +
                    " | New Score: " +
                    to_string(score));*/
   // To do: (shows up twice)
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

void Score::WriteOnScoreLog(string text)
{
  logger->writeToLog(Scor,text);
}
