/* Header for 2048 game board
   Amy Feng
   5/16/2018
*/
#include <iostream>
using namespace std;

class GameBoard
{
  public:
    GameBoard();

    void PrintBoard();

  private:
    const static int ROW_NUM = 4;
    const static int COL_NUM = 4;

    int board_nums [ROW_NUM][COL_NUM];
};
