all:
	gcc -Wall -Wextra -lncurses main.c -o main.out
clean:
	rm *.out
