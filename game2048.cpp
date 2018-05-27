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
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
}

void Game2048::End()
{
  endwin();
}

void Game2048::DisplayGame()
{
  move(0,0);
  DisplayTopMenu();
  cout<< board;
  DisplayBottomMenu();
}

void Game2048::DisplayTopMenu()
{
  printw("*************************************************************************************************\n");
  printw("*            *             *           *****          *            *             *              *\n");
  printw("*  REDO (R)  *  RESET (S)  *  EXIT(E)  *****  UP (^)  *  DOWN (v)  *  LEFT (<-)  *  RIGHT (->)  *\n");
  printw("*            *             *           *****          *            *             *              *\n");
  printw("*************************************************************************************************\n");
  printw("\n");

}

void Game2048::DisplayBottomMenu()
{
  // TO DO MAKE FLEXEBLE
  // TO DO CENTER TEXT FUNCTION
  int space = 33;
  string str = to_string(score.getScore());
  int length = str.length();

  printw("*************************************************************************************************\n");
  printw("*              SCORE              *                                                             *\n");
  printw("*                                 *                                                             *\n");
  printw("*");

  printw("%*s%*c",
          ((space - length) >> 1) + length,
          str.c_str(),
          ((space - length) >> 1) + ((space - length) & 1),
          ' '
        );
  printw("*                                                             *\n");
  printw("*                                 *                                                             *\n");
  printw("*************************************************************************************************\n");
  printw("\n");
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
  bool objective2048 = true;
  int key = -1;
  int row,col;

  SetUpGame();
  key = input.Input();

  while(key!=(int)'e')
  {
    while(contGame || key==(int)'r')
    {
        if(key!=(int)'e')
        {
          if(key!=(int)'s')
          {
            if(key!=(int)'r')
            {
              if(key!=(int)'c' && key!=-1)
              {
                collision = collDetec.shiftAll(key, found2048);
                WriteOnGameLog(string("Found2048 Result: ") +  ((found2048) ? "True" : "False") + "\n");

                if(collision)
                {
                  piece.setBoard();
                  // TO DO ADD COLOR
                  DisplayGame();

                  if(objective2048)
                  {
                    contGame = (!found2048) && collDetec.testShift();
                  }
                  else
                  {
                    contGame = collDetec.testShift();
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
        getmaxyx(stdscr,row,col);
        mvprintw(row/2,(col-strlen(getLostMessage().c_str()))/2,"%s",getLostMessage().c_str());
        refresh();
        WriteOnGameLog("User LOST!\n");
        showLostMessage = false;
      }

      if(key==(int)'e')
      {
        break;
      }

      if(objective2048 && found2048)
      {
        Win(contGame, objective2048, key);
      }
      else
      {
        key = input.Input();
      }

      if(key==(int)'r')
      {
        contGame = true;
        showLostMessage = true;
      }
  }

  /*getmaxyx(stdscr,row,col);
  mvprintw(row/2,(col-strlen(getGameOverMessage().c_str()))/2,"%s",getGameOverMessage().c_str());
  refresh();*/
}

// TO DO: Needs multi-threading - might need timer class
void Game2048::TimerToCont()
{
  clock_t start = clock();
  printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
}

void Game2048::Win(bool& contGame, bool& objective2048, int& key)
{
  // TO DO: Make center
  mvprintw(0,0,"YOU WIN\n");
  WriteOnGameLog("User Won!\n");
  // add timer for press?
  printw("Press (c) to continue\n");
  key = input.Input();
  if(key==(int)'c')
  {
    WriteOnGameLog("Continuing game after 2048 goal\n");
    contGame = true;
    objective2048 = false;
    DisplayGame();
  }
  else
  {
    key = (int)'e';
    WriteOnGameLog("Did not continuing game after 2048 goal\n");
  }
}

void Game2048::Redo()
{
  collDetec.UndoCollision();
  DisplayGame();
  showLostMessage = true;
  WriteOnGameLog("Redoing Board ...\n");
}

void Game2048::Reset()
{
  board.boardReset();
  score.scoreReset();
  piece.setBoard();
  piece.setBoard();
  DisplayGame();
  WriteOnGameLog("Resetting Board ...\n");
}

void Game2048::WriteOnGameLog(string text)
{
  logger->writeToLog(Game,text);
}

// Not printing write - need to add flex
string Game2048::getLostMessage()
{
  return (string("***************************\n") +
          string("*                         *\n") +
          string("*         YOU LOST        *\n") +
          string("*                         *\n") +
          string("***************************\n"));
}
