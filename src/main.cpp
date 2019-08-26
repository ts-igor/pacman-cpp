#include "PMGame.h"

#include <iostream>
#include <cstdlib>
#include <ncurses.h>
using namespace std;

int main () {

	PMGame pacman;
	int choice;
	
	try {
	
		do {
		choice = pacman.mainMenu();		
			switch (choice) {
				case 1: {
					keypad(stdscr, FALSE);
					pacman.startGame();
					keypad(stdscr, TRUE);
					break;
				}
				case 2: {
					keypad(stdscr, FALSE);
					pacman.difficultySettings();
					keypad(stdscr, TRUE);
					break;
				}	
			}
		} while (choice != 3);

		pacman.exitGame();		

	}
	
	catch (const char * err) {
		clear();
		refresh();
		endwin();
		system("clear");	
		cout << "ERROR: " <<err << endl;
	}

return 0;
}
