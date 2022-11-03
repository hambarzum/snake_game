#include <iostream>
#include <ncurses.h>
#include <stdio.h>

//#include "game.hpp"

int main() {
	initscr();
	refresh();
	WINDOW* win = newwin(20, 20, 10, 10);
	box(win, 0, 0);
	wrefresh(win);
	getch();
	endwin();
	std::cout << "Hello, World!" << std::endl;
	return 0;
	//Game game;
}
