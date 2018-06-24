/* Color Block Struct
   Defines the color
   sections of the display
   Amy Feng
   5/16/2018
*/

#ifndef COLOR_BLOCK_H
#define COLOR_BLOCK_H
#include "colors.h"
#include "position.h"
using namespace colorOpt;

struct ColorBlock
{
  Position pos;
  int length;
  int width;
  Color color;

  bool operator<(const ColorBlock& block) const
  {
    bool result = false;
    if(pos.row < block.pos.row)
    {
      result = true;
    }
    else if(pos.row == block.pos.row)
    {
      if(pos.col < block.pos.col)
      {
        result = true;
      }
    }

    return result;
  }
};

#endif
