#include <stdio.h>
#include <ncurses.h>
#include <string.h>

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

struct todo
{
  bool done;
  char str[];
};

int main(void){

  initscr();
  noecho();

  int sizeY, sizeX;
  char msg[] = "Hello, World";
  
  while (!quit)
    {
      // Get the size of the terminal
      getmaxyx(stdscr, sizeY, sizeX);
      
      // Clean the screen
      erase();

      // Render stuff
      move(sizeY/2, (sizeX-strlen(msg))/2);
      
      printw(msg);    

      // Get the control char
      control(getch());

      // Refresh screen
      refresh();
    }
  endwin();
      
  return 0;
}
