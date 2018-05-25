/* Source code for main game class
   Amy Feng
   5/18/2018
*/
#include "Game2048.h"

Game2048::Game2048():board(10,6,2),piece(pieces,board),collDetec(board,score,2048)
{
  Game2048::contGame = true;
  pieces.push_back(2);
  pieces.push_back(4);
  collision = false;
  found2048 = false;
  Objective2048 = true;
  key = OTHER;
}

void Game2048::ClearScreen()
{
  cout << string( 100, '\n' );
}

void Game2048::DisplayGame(int score, GameBoard board)
{
  DisplayTopMenu();
  board.PrintBoard();
  DisplayBottomMenu(score);
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

void Game2048::DisplayBottomMenu(int score)
{
  // TO DO MAKE FLEXEBLE
  // TO DO CENTER TEXT FUNCTION
  int space = 33;
  string str = to_string(score);
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

void Game2048::Start()
{
  piece.setBoard();
  piece.setBoard();
  DisplayGame(score.getScore(),board);

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
            DisplayGame(score.getScore(),board);

            if(Objective2048)
            {
              contGame = (!found2048) && collDetec.testShift();
            }
            else
            {
              contGame = collDetec.testShift();
            }

            if(Objective2048 && found2048)
            {
              cout<< "YOU WIN" << endl;
              // add timer for press?
              cout<< "Press (SHIFT + C) to continue" << endl;
              key = input.Input();
              if(key==CONT)
              {
                contGame = true;
                Objective2048 = false;
              }
            }
          }
        }
      }
      else
      {
        collDetec.UndoCollision();
        DisplayGame(score.getScore(),board);
      }
    }
    else
    {
      board.boardReset();
      score.scoreReset();
      piece.setBoard();
      piece.setBoard();
      DisplayGame(score.getScore(),board);
    }
  }

  cout<< "GAME OVER" << endl;
}
