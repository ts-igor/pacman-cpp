#include "PMGreatFood.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMGreatFood::PMGreatFood(int y, int x) : PMField(y, x) {

	mSymbol = '$';													
	init_pair(11, COLOR_RED, COLOR_BLACK);							// Initializing a color pair for Great Food

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMGreatFood::~PMGreatFood() {}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGreatFood::drawField(WINDOW * w) const {

	attron(COLOR_PAIR(11));
	mvwaddch(w, posY + Y_SHIFT, posX + X_SHIFT, mSymbol);
	attroff(COLOR_PAIR(11));
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGreatFood::interact(PMPacman * pm) {

	if (mInteraction) {
		pm->addScore(100);
		mSymbol = ' ';												// Setting the symbol as an empty field
		mInteraction = false;										// This field does not interact with Pacman no more
		drawField(stdscr);
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
