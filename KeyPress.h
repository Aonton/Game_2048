/* Enum for key press values
   Amy Feng
   5/20/2018
*/

#ifndef KEY_PRESS
#define KEY_PRESS
namespace keyPress
{
  typedef enum
  {
    KEY_UP = 65,
    KEY_DOWN = 66,
    KEY_RIGHT = 67,
    KEY_LEFT = 68,
    REDO = 114,
    EXIT = 101,
    CONT = 99,
    RESET = 115,
    OTHER = -1
  } Keys;
}

#endif
