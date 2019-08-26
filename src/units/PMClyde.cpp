#include "PMClyde.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMClyde::PMClyde(PMMap & m, int i, PMPacman * p) : PMMonster(m, i, p) {

	init_color(COLOR_GREEN, 1000, 400, 280); 								// Redefining green color constant to make it orange
	init_pair(5, COLOR_GREEN, COLOR_BLACK);

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMClyde::~PMClyde() {}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMClyde::draw() const {

	attron(COLOR_PAIR(5));
	mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
	attroff(COLOR_PAIR(5));

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMClyde::chase() {

	if (onTeleport()) {
		teleport();
		draw();
	}
	else if (dead()) {
		toShelter();
	}
	else if (inShelter()) {
		if (countDirections() > 1) {
			turn(11, 13);
		}
		else step();
		draw();
	}
	else if (countDirections() > 1) {
		pair<int,int> p = mPacman->getCoords();
		
		if (countDistance(mY, mX, p.first, p.second) > 8.0) {
			turn(p.first, p.second);
		}
		else {
			turn(33, 0);
		}
		
		draw();
	}
	else {
		step();
		draw();
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
