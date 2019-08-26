#include "PMMenu.h"

//----------------------------------------------------------------------------------------------------------------------------------------
int PMMenu::drawMainMenu() {

	clear();
	
	WINDOW * mainMenuWin;
	
	int highlight = 1;
	int choice = 0;
	int c;
	
	const char * choices[] = { 
		"New Game",
		"Difficulty Settings",
		"Exit"
	};
	
	int n_choices = sizeof(choices) / sizeof(char *);
	

	mainMenuWin = newwin(WIN_HEIGHT, WIN_WIDTH, startY, startX);
	keypad(mainMenuWin, TRUE);
	
	mvprintw(startY - 2, startX - 12, "Use arrow keys to go up and down, press enter to select");
	refresh();
	
	showWindow(mainMenuWin, choices, n_choices, highlight);
	do {	
		c = wgetch(mainMenuWin);
		switch (c) {	
			case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case ENTER_KEY:
				choice = highlight;
				break;
		}
		showWindow(mainMenuWin, choices, n_choices, highlight);
		/* User did a choice come out of the infinite loop */
	} while (choice == 0);
	
	return choice;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMMenu::drawDifficultySettings() {

	clear();
	
	WINDOW * mainMenuWin;
	
	int highlight = 1;
	int choice = 0;
	int c;
	
	const char * choices[] = { 
		"	1	",
		"	2	",
		"	3	",
		"	4	",
	};
	
	int n_choices = sizeof(choices) / sizeof(char *);
	

	mainMenuWin = newwin(WIN_HEIGHT, WIN_WIDTH, startY, startX);
	keypad(mainMenuWin, TRUE);
	
	mvprintw(startY - 2, startX - 12, "Use arrow keys to go up and down, press enter to select");
	refresh();
	
	showWindow(mainMenuWin, choices, n_choices, highlight);
	do {	
		c = wgetch(mainMenuWin);
		switch (c) {	
			case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case ENTER_KEY:
				choice = highlight;
				break;
		}
		showWindow(mainMenuWin, choices, n_choices, highlight);
		/* User did a choice come out of the infinite loop */
	} while (choice == 0);
	
	return choice;

	return 0;

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMenu::showWindow(WINDOW * menuWin, const char * choices[], int n_choices, int highlight) {
	
	int x, y, i;
	
	x = 2;
	y = 2;
	box(menuWin, 0, 0);
	for(i = 0; i < n_choices; ++i) {
		/* High light the present choice */	
		if(highlight == i + 1) {
			wattron(menuWin, A_REVERSE); 
			mvwprintw(menuWin, y, x, "%s", choices[i]);
			wattroff(menuWin, A_REVERSE);
		}
		else
			mvwprintw(menuWin, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menuWin);
}
//----------------------------------------------------------------------------------------------------------------------------------------
