#include "PMPinky.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMPinky::PMPinky(PMMap & m, int i, PMPacman * p) : PMMonster(m, i, p) {

	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMPinky::~PMPinky() {}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPinky::draw() const {

	attron(COLOR_PAIR(3));
	mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
	attroff(COLOR_PAIR(3));

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPinky::chase() {

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
		int y = p.first;
		int x = p.second;
		switch (mPacman->getDirection()) {
			case KEY_UP : {
				y = y - 4;
				break;
			}
			case KEY_DOWN : {
				y = y + 4;
				break;
			}
			case KEY_LEFT : {
				x = x - 4;
				break;
			}
			case KEY_RIGHT : {
				x = x + 4;
				break;
			}
		}
		turn(y, x);
		draw();
	}
	else {
		step();
		draw();
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
