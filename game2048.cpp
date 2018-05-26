/* Source code for main game class
   Amy Feng
   5/18/2018
*/
#include "Game2048.h"

Game2048::Game2048(Log& log):board(10,6,2,log),
                             collDetec(board,score,2048,log),
                             piece(pieces,board,log),
                             score(log),
                             input(log)
{
  pieces.push_back(2);
  pieces.push_back(4);
  Game2048::logger = &log;
  Game2048::showLostMessage = true;
  Game2048::contGame = true;
}

void Game2048::ClearScreen()
{
  cout << string( 100, '\n' );
}

void Game2048::DisplayGame()
{
  DisplayTopMenu();
  cout<< board;
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
  bool collision = false;
  bool found2048 = false;
  bool objective2048 = false;
  Keys key = OTHER;

  SetUpGame();
  key = input.Input();

  while(key!=EXIT)
  {
    while(contGame || key==REDO)
    {
        if(key!=EXIT)
        {
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
                  //ClearScreen();
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
              contGame = true;
            }
          }
          else
          {
            Reset();
          }
        }
        else
        {
          break;
        }

        if(contGame)
        {
            key = input.Input();
        }
      }

      if(!found2048 && showLostMessage && !contGame)
      {
        cout<< "YOU LOST" << endl;
        WriteOnGameLog("User LOST!");
        showLostMessage = false;
      }

      if(key==EXIT)
      {
        break;
      }

      key = input.Input();

      if(key==RESET)
      {
        contGame = true;
        showLostMessage = true;
      }
  }

  cout<< "GAME OVER" << endl;
}

// TO DO: Needs multi-threading - might need timer class
void Game2048::TimerToCont()
{
  clock_t start = clock();
  printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
}

void Game2048::Win(bool& contGame, bool& objective2048)
{
  Keys key;
  cout<< "YOU WIN" << endl;
  WriteOnGameLog("User Won!");
  // add timer for press?
  cout<< "Press (SHIFT + C) to continue" << endl;
  key = input.Input();
  if(key==CONT)
  {
    contGame = true;
    objective2048 = false;
    WriteOnGameLog("Continuing game after 2048 goal");
  }
}

void Game2048::Redo()
{
  collDetec.UndoCollision();
  DisplayGame();
  showLostMessage = true;
  WriteOnGameLog("Redoing Board ...");
}

void Game2048::Reset()
{
  board.boardReset();
  score.scoreReset();
  piece.setBoard();
  piece.setBoard();
  DisplayGame();
  WriteOnGameLog("Resetting Board ...");
}

void Game2048::WriteOnGameLog(string text)
{
  logger->writeToLog(Game,text);
}
