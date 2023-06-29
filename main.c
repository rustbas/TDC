#include <stdio.h>
#include <ncurses.h>

bool quit = false;

void control(char c)
{
  switch(c)
    {
      case 'q':
	quit = true;
	break;
    }
}

int main(void){

  initscr();
  noecho();
  printw("Hello, World!\n");
  refresh();
  while (!quit)
    {
      control(getch());
    }
  endwin();
      
  return 0;
}
