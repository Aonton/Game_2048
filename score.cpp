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
