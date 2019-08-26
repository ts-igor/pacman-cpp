#include "PMPacman.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMPacman::PMPacman(PMMap & map) : PMUnit(map) {

	mHealth = 2;
	mEaten = 0;
	mScore = 0;
	mSymbol = '0';
	mClock = 0;
	mScatter = false;
	mDirection = KEY_LEFT;

	pair<int,int> p = mMap->getPacmanSpawn(); 
	mStartY = p.first;
	mStartX = p.second;
	
	init_color(COLOR_YELLOW, 1000, 1000, 0);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	
	mFields = mMap->getFields();

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMPacman::~PMPacman() {}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::move(int key) {
	
	if (mDirection != key) {
		changeDirection(key);
	}
	
	mFields[mY][mX]->interact(this);

	switch (mDirection) {
		case KEY_UP : {
			if (mMap->access(mY - 1, mX)) {
				mY--;
			}
			break;
		}
		case KEY_DOWN : {
			if (mMap->access(mY + 1, mX)) {
				mY++;
			}
			break;
		}
		case KEY_LEFT : {
			if (mMap->access(mY, mX - 1)) {
				mX--;
			}
			break;
		}
		case KEY_RIGHT : {
			if (mMap->access(mY, mX + 1)) {
				mX++;
			}
			break;
		}

	}
	
	draw();

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::changeDirection(int key) {

	switch (key) {
	
		case KEY_UP : {
			if (mMap->access(mY - 1, mX)) {
				mDirection = KEY_UP;
			}
			break;
		}
		case KEY_DOWN : {
			if (mMap->access(mY + 1, mX)) {
				mDirection = KEY_DOWN;
			}
			break;
		}
		case KEY_LEFT : {
			if (mMap->access(mY, mX - 1)) {
				mDirection = KEY_LEFT;
			}
			break;
		}
		case KEY_RIGHT : {
			if (mMap->access(mY, mX + 1)) {
				mDirection = KEY_RIGHT;
			}
			break;
		}
		
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMPacman::getHealth() const {

	return mHealth;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::decHealth()  {

	--mHealth;

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::addScore(int s) {

	mScore += s;

}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMPacman::getScore() const {
	
	return mScore;

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::draw() const	 {

	attron(COLOR_PAIR(1) | A_BLINK);
	mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol); 
	attroff(COLOR_PAIR(1) | A_BLINK);

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::changeCoordinates(int y, int x) {

	// Depending on direction we add +1 or -1 in order to avoid stucking between teleports
	switch (mDirection) {	
		case KEY_UP : {
			mY = y - 1;
			mX = x;
			break;
		}
		case KEY_DOWN : {
			mY = y + 1;
			mX = x;
			break;
		}
		case KEY_LEFT : {
			mY = y;
			mX = x - 1;
			break;
		}
		case KEY_RIGHT : {
			mY = y;
			mX = x + 1;
			break;
		}
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::eatFood() {

	mEaten++;

}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMPacman::foodEaten() const {

	return mEaten;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::refreshFood() {

	mEaten = 0;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::scatterModeOn() {

	mScatter = true;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMPacman::scatterMode() {

	if (mScatter && mClock < 50) {
		mClock++;
	}
	else {
		mScatter = false;
		mClock = 0;
	}
	
	return mScatter;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMPacman::scatterModeOff() {
	
	mScatter = false;
	mClock = 0;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMPacman::getDirection() const {

	return mDirection;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
