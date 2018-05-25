/* Source code for main game class
   Amy Feng
   5/18/2018
*/
#include "Game2048.h"

Game2048::Game2048():board(10,6,2), collDetec(board,score,2048), piece(pieces,board)
{
  pieces.push_back(2);
  pieces.push_back(4);
}

void Game2048::ClearScreen()
{
  cout << string( 100, '\n' );
}

void Game2048::DisplayGame()
{
  DisplayTopMenu();
  board.PrintBoard();
  DisplayBottomMenu();
}

void Game2048::DisplayTopMenu()
{
  cout<< "*************************************************************************************************" << endl;
  cout<< "*            *             *           *****          *            *             *              *" << endl;
  cout<< "*  REDO (R)  *  RESET (S)  *  EXIT(E)  *****  UP (^)  *  DOWN (v)  *  LEFT (<-)  *  RIGHT (->)  *" << endl;
  cout<< "*            *             *           *****          *            *             *              *" << endl;
  cout<< "*************************************************************************************************" << endl;
  cout<< endl;

}

void Game2048::DisplayBottomMenu()
{
  // TO DO MAKE FLEXEBLE
  // TO DO CENTER TEXT FUNCTION
  int space = 33;
  string str = to_string(score.getScore());
  int length = str.length();

  cout<< "*************************************************************************************************" << endl;
  cout<< "*              SCORE              *                                                             *" << endl;
  cout<< "*                                 *                                                             *" << endl;
  cout<< "*";

  printf ("%*s%*c",
          ((space - length) >> 1) + length,
          str.c_str(),
          ((space - length) >> 1) + ((space - length) & 1),
          ' '
        );
  cout<< "*                                                             *" << endl;
  cout<< "*                                 *                                                             *" << endl;
  cout<< "*************************************************************************************************" << endl;
  cout<< endl;
}

void Game2048::SetUpGame()
{
  piece.setBoard();
  piece.setBoard();
  DisplayGame();
}

void Game2048::Start()
{
  bool contGame = true;
  bool collision = false;
  bool found2048 = false;
  bool objective2048 = false;
  Keys key = OTHER;

  SetUpGame();

  while(contGame)
  {
    key = input.Input();
    if(key!=RESET)
    {
      if(key!=REDO)
      {
        if(key!=CONT && key!=OTHER)
        {
          collision = collDetec.shiftAll(key, found2048);

          if(collision)
          {
            piece.setBoard();
            // DO NOT CLEAR SCREEN FIX POSITION
            // TO DO ADD COLOR
            ClearScreen();
            DisplayGame();

            if(objective2048)
            {
              contGame = (!found2048) && collDetec.testShift();
            }
            else
            {
              contGame = collDetec.testShift();
            }

            if(objective2048 && found2048)
            {
              Win(contGame, objective2048);
            }
          }
        }
      }
      else
      {
        Redo();
      }
    }
    else
    {
      Reset();
    }
  }

  cout<< "GAME OVER" << endl;
}

void Game2048::TimerToCont()
{
  clock_t start = clock();
}

void Game2048::Win(bool& contGame, bool& objective2048)
{
  Keys key;
  cout<< "YOU WIN" << endl;
  // add timer for press?
  cout<< "Press (SHIFT + C) to continue" << endl;
  key = input.Input();
  if(key==CONT)
  {
    contGame = true;
    objective2048 = false;
  }
}

void Game2048::Redo()
{
  collDetec.UndoCollision();
  DisplayGame();
}

void Game2048::Reset()
{
  board.boardReset();
  score.scoreReset();
  piece.setBoard();
  piece.setBoard();
  DisplayGame();
}
