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

typedef struct
{
  bool done;
  char name[100];
} todo;


#define sizeTodo 2

int main(void){
  todo tds[sizeTodo];

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

      for (int i = 0; i < sizeTodo;i++) {
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
