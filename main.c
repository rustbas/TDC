#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define TODO_NAME_MAX_SIZE 100
#define SIZE_TODO_LIST 2

#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))

bool quit = false;
int currLine = 0;

void control(char c, char *tds[][TODO_NAME_MAX_SIZE])
{
  switch(c)
    {
    case 'q':
      quit = true;
      break;
    case 'j':
      currLine = min(currLine + 1, (int) (sizeof(**tds)/sizeof(*tds[0])) - 1);
      break;
    case 'k':
      currLine = max(currLine - 1, 0);
      break;
    }
}

void renderTodoList(){
}

void renderCurrLine(){
}

int main(void){

  char **tds;
  tds = (char **) malloc(sizeof(char*) * 2);
  tds[0] = "test1";
  tds[1] = "test2";
  
  initscr();
  noecho();
  curs_set(0);

  int sizeY, sizeX;

  //Check color support
  if (has_colors() == false) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
  }

  start_color();
  
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_RED);

  while (!quit)
    {
      // Get the size of the terminal
      getmaxyx(stdscr, sizeY, sizeX);
      //WINDOW *win = newwin(1, sizeX-3, currLine, 0);
      
      // Clean the screen
      erase();

      // Render stuff
      //bkgd(COLOR_PAIR(1));
      //wbkgd(win, COLOR_PAIR(2));
      box(stdscr, 0,0);

      int sizeTodoList = sizeof(tds)/sizeof(tds[0]);
      
      for (int i = 0; i < sizeTodoList; i++) {
	move(i+1, 1);

	if (currLine == i) {
	  printw("-->[%d]: %s", i+1, tds[i]);
	} else {
	  printw(" - [%d]: %s", i+1, tds[i]); // Rewrite using WINDOW
	};
	
      }

      move(sizeTodoList+1, 1);
      printw("currLine = %d", currLine + 1);
      
      // Get the control char
      control(getch(), tds);
      
      // Refresh screen
      refresh();
    }
  endwin();
      
  return 0;
}
