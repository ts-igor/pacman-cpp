#include "PMBonus.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMBonus::PMBonus(int y, int x) : PMField(y, x) {

	mSymbol = '#';

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMBonus::~PMBonus() {}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMBonus::drawField(WINDOW * w) const {

	attron(A_BOLD);
	mvwaddch(w, posY + Y_SHIFT, posX + X_SHIFT, mSymbol);
	attroff(A_BOLD);

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMBonus::interact(PMPacman * pm) {

	if (mInteraction) {
		mSymbol = ' ';												// Setting the symbol as an empty field
		mInteraction = false;										// This field does not interact with Pacman no more
		pm->scatterModeOn();
		drawField(stdscr);
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------

