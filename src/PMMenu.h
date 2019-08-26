/**
	Class for drawing main menu and taking user's choices
*/
#ifndef MENU
#define MENU


#include <ncurses.h>


static const int TERM_HEIGHT = 43;								///< Terminal height that will be used
static const int TERM_WIDTH = 80;								///< Terminal wifth that will be used

static const int WIN_HEIGHT = 10;
static const int WIN_WIDTH = 30;

const int ENTER_KEY = 10;

class PMMenu {

private:

	static const int startX = (TERM_WIDTH - WIN_WIDTH) / 2;			///< Start X position for drawing menu
	static const int startY = (TERM_HEIGHT - WIN_HEIGHT) / 2;			///< Start Y position for drawing menu

	/**
		Shows the window and highlights the item
		\param w Window to be shown
		\param s Text to write in the window
		\param c Number of choices in the text
		\param h Highlighted choice
	*/
	void showWindow(WINDOW*, const char *[], int, int);	

public:
	
	/**
		Drawing main menu
	*/
	int drawMainMenu();											
	
	/**
		Drawing difficulty settings menu
	*/
	int drawDifficultySettings();
	
};


#endif // MENU
