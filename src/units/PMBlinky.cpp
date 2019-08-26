#include "PMBlinky.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMBlinky::PMBlinky(PMMap & m, int i, PMPacman * p) : PMMonster(m, i, p) {

	init_pair(2, COLOR_RED, COLOR_BLACK);

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMBlinky::~PMBlinky() {}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMBlinky::draw() const {

	attron(COLOR_PAIR(2));
	mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
	attroff(COLOR_PAIR(2));

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMBlinky::chase() {
	
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
		turn(p.first, p.second);
		draw();
	}
	else {
		step();
		draw();
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
