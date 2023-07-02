#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#define TODO_NAME_SIZE 100
#define SIZE_TODO_LIST 2

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

  int sizeY, sizeX;
  char msg[] = "Hello, World";
  
  while (!quit)
    {
      // Get the size of the terminal
      getmaxyx(stdscr, sizeY, sizeX);
      
      // Clean the screen
      erase();

      // Render stuff
      //move(sizeY/2, (sizeX-strlen(msg))/
      //printw(msg);    

      for (int i = 0; i < SIZE_TODO_LIST;i++) {
	move(i, 0);
	printw(tds[i].name);
      }
      
      // Get the control char
      control(getch());

      // Refresh screen
      refresh();
    }
  endwin();
      
  return 0;
}
