#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define TODO_NAME_SIZE 100
#define SIZE_TODO_LIST 2

#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))

bool quit = false;
int currLine = 0;

void control(char c)
{
  switch(c)
    {
    case 'q':
      quit = true;
      break;
    case 'j':
      currLine = min(currLine + 1, SIZE_TODO_LIST - 1);
      break;
    case 'k':
      currLine = max(currLine - 1, 0);
      break;
    }
}

typedef struct
{
  bool done;
  char name[TODO_NAME_SIZE];
} todo;

int main(void){
  todo tds[SIZE_TODO_LIST];

  //tds.done = false;
  //tds.name = "test1";
  tds[0].done = false;
  strcpy(tds[0].name,"test1");
  tds[1].done = false;
  strcpy(tds[1].name,"test2");
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
      WINDOW *win = newwin(1, sizeX-3, currLine, 0);
      
      // Clean the screen
      erase();

      // Render stuff
      //move(sizeY/2, (sizeX-strlen(msg))/
      //printw(msg);    
      bkgd(COLOR_PAIR(1));
      wbkgd(win, COLOR_PAIR(2));
      //box(win, 0,0);

      for (int i = 0; i < SIZE_TODO_LIST;i++) {
	move(i, 0);
	printw("- [%d]: %s", i+1, tds[i].name); // Rewrite using WINDOW
      }

      move(SIZE_TODO_LIST, 0);
      printw("currLine = %d", currLine + 1);
      
      // Get the control char
      control(getch());
      
      // Refresh screen
      refresh();
      wrefresh(win);
    }
  endwin();
      
  return 0;
}
