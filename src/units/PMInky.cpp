#include "PMInky.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMInky::PMInky(PMMap & m, int i, PMPacman * p, PMMonster * bl) : PMMonster(m, i, p) {

	mBlinky = bl;
	init_pair(4, COLOR_CYAN, COLOR_BLACK);

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMInky::~PMInky() {}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMInky::draw() const {

	attron(COLOR_PAIR(4));
	mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
	attroff(COLOR_PAIR(4));

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMInky::chase() {

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
				y = y - 2;
				break;
			}
			case KEY_DOWN : {
				y = y + 2;
				break;
			}
			case KEY_LEFT : {
				x = x - 2;
				break;
			}
			case KEY_RIGHT : {
				x = x + 2;
				break;
			}
		}
		int finalY = findTarget(mBlinky->getCoords().first, y);
		int finalX = findTarget(mBlinky->getCoords().second, x);
		
		turn(finalY, finalX);
		draw();
	}
	else {
		step();
		draw();
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMInky::findTarget(int blinky, int pacman) const {

	if (blinky <= pacman) {
		return pacman + (pacman - blinky);
	}
	else {
		return pacman - (blinky - pacman);
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
