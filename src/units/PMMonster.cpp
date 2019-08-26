#include "PMMonster.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMMonster::PMMonster(PMMap & m, int i, PMPacman * p) : PMUnit(m) {

	pair<int, int> ps = mMap->getMonsterSpawn(i);
	mStartY = ps.first;
	mStartX = ps.second;
	mY = mStartY;
	mX = mStartX;
	mSymbol = '@';
	mPacman = p;
	mDirection = KEY_LEFT;
	mDead = false;
	mSlow = true;
	init_pair(6, COLOR_BLUE, COLOR_BLUE);
	
	mFirstTeleport = mMap->getFirstTeleport();
	mSecondTeleport = mMap->getSecondTeleport();
	
	mShelter.insert(make_pair(13, 11));
	mShelter.insert(make_pair(13, 12));
	mShelter.insert(make_pair(13, 13));
	mShelter.insert(make_pair(13, 14));
	mShelter.insert(make_pair(13, 15));
	mShelter.insert(make_pair(13, 16));
	mShelter.insert(make_pair(14, 11));
	mShelter.insert(make_pair(14, 12));
	mShelter.insert(make_pair(14, 13));
	mShelter.insert(make_pair(14, 14));
	mShelter.insert(make_pair(14, 15));
	mShelter.insert(make_pair(14, 16));
	mShelter.insert(make_pair(15, 11));
	mShelter.insert(make_pair(15, 12));
	mShelter.insert(make_pair(15, 13));
	mShelter.insert(make_pair(15, 14));
	mShelter.insert(make_pair(15, 15));
	mShelter.insert(make_pair(15, 16));
	mShelter.insert(make_pair(16, 11));
	mShelter.insert(make_pair(16, 12));
	mShelter.insert(make_pair(16, 13));
	mShelter.insert(make_pair(16, 14));
	mShelter.insert(make_pair(16, 15));
	mShelter.insert(make_pair(16, 16));
	mShelter.insert(make_pair(12, 13));
	mShelter.insert(make_pair(12, 14));

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMMonster::~PMMonster() {}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMMonster::countDirections() const {

	int c = 0;

	if (accessUp() && mDirection != KEY_DOWN) {
		c++;
	} 
	if (accessDown() && mDirection != KEY_UP ) {
		c++;
	}
	if (accessLeft() && mDirection != KEY_RIGHT) {
		c++;
	} 
	if (accessRight() && mDirection != KEY_LEFT) {
		c++;
	}

	return c;

}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::inShelter() {

	return (mShelter.count( make_pair(mY, mX) ) > 0);

}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::notShelter(int y, int x) const {

	return !(mShelter.count( make_pair(y, x) ) > 0) || dead();

}
//----------------------------------------------------------------------------------------------------------------------------------------
double PMMonster::countDistance(int y1, int x1, int y2, int x2) const {

	// Co-ordinates start with 0, so we add +1;
	y1++; x1++;
	y2++; x2++;
	
	// Inversing values because of inversed Y
	y1 = -y1;
	y2 = -y2;
	return sqrt( (y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1) );

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::turnUp() {

	mY--;
	mDirection = KEY_UP;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::turnDown() {

	mY++;
	mDirection = KEY_DOWN;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::turnLeft() {

	mX--;
	mDirection = KEY_LEFT;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::turnRight() {

	mX++;
	mDirection = KEY_RIGHT;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::accessUp() const {

	return mMap->access(mY - 1, mX);
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::accessDown() const {

	return mMap->access(mY + 1, mX) && notShelter(mY + 1, mX);
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::accessLeft() const {

	return mMap->access(mY, mX - 1);
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::accessRight() const {

	return mMap->access(mY, mX + 1);
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::turn(int y, int x) {

	switch (mDirection) {
		case KEY_UP : {
			/* Chooses the best turn if comes from downside */
			if (accessUp() && accessLeft() && accessRight()) {
				double left = countDistance(mY, mX - 1, y, x);
				double right = countDistance(mY, mX + 1, y, x);
				double up = countDistance(mY - 1, mX, y, x);

				if ((left < right && left < up) || (left == right && left < up)) {
					turnLeft();
				}
				else if (right < left && right < up) {
					turnRight();
				}
				else if ((up < left && up < right) || (up == left) || (up == right)) {
					turnUp();
				}
			}
			else if (accessUp() && accessLeft()) {
				double up = countDistance(mY - 1, mX, y, x);
				double left = countDistance(mY, mX - 1, y, x);
				
				if (up < left) {
					turnUp();
				}
				else if (left < up) {
					turnLeft();	
				}
				else if (left == up) {
					turnUp();
				}
			}
			else if (accessUp() && accessRight()) {
				double up = countDistance(mY - 1, mX, y, x);
				double right = countDistance(mY, mX + 1, y, x);
				
				if (up < right) {
					turnUp();
				}
				else if (right < up) {
					turnRight();
				}
				else if (right == up) {
					turnUp();
				}
			}
			else if (accessLeft() && accessRight()) {
				double right = countDistance(mY, mX + 1, y, x);
				double left = countDistance(mY, mX - 1, y, x);
				
				if (left < right) {
					turnLeft();
				}
				else if (right < left) {
					turnRight();
				}
				else if (right == left) {
					turnLeft();
				}
			}
		break;
		}
		
		
		case KEY_DOWN : {
			/* Chooses the best turn if comes from upside */
			if (accessLeft() && accessRight() && accessDown()) {
				double left = countDistance(mY, mX - 1, y, x);
				double right = countDistance(mY, mX + 1, y, x);
				double down = countDistance(mY + 1, mX, y, x);

				if ((left < right && left < down) || (left == right && left < down) || (left == down && left < right)) {
					turnLeft();
				}
				else if (right < left && right < down) {
					turnRight();
				}
				else if ((down < left && down < right) || (down == right)) {
					turnDown();
				}
			}
			else if (accessLeft() && accessDown()) {
				double down = countDistance(mY + 1, mX, y, x);
				double left = countDistance(mY, mX - 1, y, x);
				
				if (down < left) {
					turnDown();
				}
				else if (left < down) {
					turnLeft();	
				}
				else if (left == down) {
					turnLeft();
				}
			}
			else if (accessRight() && accessDown()) {
				double down = countDistance(mY + 1, mX, y, x);
				double right = countDistance(mY, mX + 1, y, x);
				
				if (down < right) {
					turnDown();
				}
				else if (right < down) {
					turnRight();
				}
				else if (right == down) {
					turnDown();
				}
			}
			else if (accessLeft() && accessRight()) {
				double right = countDistance(mY, mX + 1, y, x);
				double left = countDistance(mY, mX - 1, y, x);
				
				if (left < right) {
					turnLeft();
				}
				else if (right < left) {
					turnRight();
				}
				else if (right == left) {
					turnLeft();
				}
			}
		break;
		}
		
		
		case KEY_LEFT : {
			/* Chooses the best turn if comes from right side */
			if (accessUp() && accessDown() && accessLeft()) {
				double left = countDistance(mY, mX - 1, y, x);
				double up = countDistance(mY - 1, mX, y, x);
				double down = countDistance(mY + 1, mX, y, x);

				if ((left < up && left < down) || (left == down && left < up)) {
					turnLeft();
				}
				else if ((up < left && up < down) || (up == left && up < down) || (up == down && up < left)) {
					turnUp();
				}
				else if (down < left && down < up) {
					turnDown();
				}
			}
			else if (accessDown() && accessLeft()) {
				double down = countDistance(mY + 1, mX, y, x);
				double left = countDistance(mY, mX - 1, y, x);
				
				if (down < left) {
					turnDown();
				}
				else if (left < down) {
					turnLeft();	
				}
				else if (left == down) {
					turnLeft();
				}
			}
			else if (accessUp() && accessDown()) {
				double down = countDistance(mY + 1, mX, y, x);
				double up = countDistance(mY - 1, mX, y, x);
				
				if (down < up) {
					turnDown();
				}
				else if (up < down) {
					turnUp();
				}
				else if (down == up) {
					turnUp();
				}
			}
			else if (accessUp() && accessLeft()) {
				double up = countDistance(mY - 1, mX, y, x);
				double left = countDistance(mY, mX - 1, y, x);
				
				if (left < up) {
					turnLeft();
				}
				else if (up < left) {
					turnUp();
				}
				else if (up == left) {
					turnUp();
				}
			}
		break;
		}
		
		
		case KEY_RIGHT : {
			/* Chooses the best turn if comes from left side */
			if (accessUp() && accessDown() && accessRight()) {
				double right = countDistance(mY, mX + 1, y, x);
				double up = countDistance(mY - 1, mX, y, x);
				double down = countDistance(mY + 1, mX, y, x);

				if (right < up && right < down) {
					turnRight();
				}
				else if ((up < right && up < down) || (up == right && up < down) || (up == down && up < right)) {
					turnUp();
				}
				else if ((down < up && down < right) || (down == right)) {
					turnDown();
				}
			}
			else if (accessDown() && accessRight()) {
				double down = countDistance(mY + 1, mX, y, x);
				double right = countDistance(mY, mX + 1, y, x);
				
				if (down < right) {
					turnDown();
				}
				else if (right < down) {
					turnRight();	
				}
				else if (right == down) {
					turnDown();
				}
			}
			else if (accessUp() && accessDown()) {
				double down = countDistance(mY + 1, mX, y, x);
				double up = countDistance(mY - 1, mX, y, x);
				
				if (down < up) {
					turnDown();
				}
				else if (up < down) {
					turnUp();
				}
				else if (down == up) {
					turnUp();
				}
			}
			else if (accessUp() && accessRight()) {
				double up = countDistance(mY - 1, mX, y, x);
				double right = countDistance(mY, mX + 1, y, x);
				
				if (right < up) {
					turnRight();
				}
				else if (up < right) {
					turnUp();
				}
				else if (up == right) {
					turnUp();
				}
			}
		break;
		}
		
		
	}
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::step() {

	switch (mDirection) {
		case KEY_UP : {
			if (accessUp()) {
				turnUp();
			}
			else if (accessLeft()) {
				turnLeft();
			}
			else if (accessRight()) {
				turnRight();
			}
		break;
		}
		case KEY_DOWN : {
			if (accessLeft()) {
				turnLeft();
			}
			else if (accessRight()) {
				turnRight();
			}
			else if (accessDown()) {
				turnDown();
			}
		break;
		}
		case KEY_LEFT : {
			if (accessUp()) {
				turnUp();
			}
			else if (accessDown()) {
				turnDown();
			}
			else if (accessLeft()) {
				turnLeft();
			}
		break;
		}
		case KEY_RIGHT : {
			if (accessUp()) {
				turnUp();
			}
			else if (accessDown()) {
				turnDown();
			}
			else if (accessRight()) {
				turnRight();
			}
		break;
		}	
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::scatter() {

	if (mSlow) {
		if (onTeleport()) {
			teleport();
			attron(COLOR_PAIR(6));
			mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
			attroff(COLOR_PAIR(6));
		}
		else if (dead()) {
			toShelter();
		}
		else if (inShelter()) {
			turn(11,13);
			attron(COLOR_PAIR(6));
			mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
			attroff(COLOR_PAIR(6)); 
		}
		else if (countDirections() > 1) {
			randomTurn();
			attron(COLOR_PAIR(6));
			mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
			attroff(COLOR_PAIR(6)); 
		}
		else {
			step();
			attron(COLOR_PAIR(6));
			mvaddch(mY + Y_SHIFT, mX + X_SHIFT, mSymbol);
			attroff(COLOR_PAIR(6)); 
		}
	}
	mSlow = !mSlow;
 
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::randomTurn() {

	int q = rand() % 100 + 1;
	
	if (q > 0 && q < 26 && accessUp()) {
		turnUp();
	}
	else if (q > 25 && q < 51 && accessDown()) {
		turnDown();
	}
	else if (q > 50 && q < 76 && accessLeft()) {
		turnLeft();
	}
	else if (q> 75 && q < 101 && accessRight()) {
		turnRight();
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::toShelter() {

	if (countDirections() > 1) {
		turn(14, 13);
	}
	else {
		step();
	}
	
	mvaddch(mY + Y_SHIFT, mX + X_SHIFT, 'X');

	if (mY == 14 && mX == 13) mDead = false;						// Resurrecting the monster

}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::dead() const {

	return mDead;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::getEaten() {

	mDead = true;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::getAlive() {

	mDead = false;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
bool PMMonster::onTeleport() const {
	
	if (mFirstTeleport != mSecondTeleport) {
		return (mY == mFirstTeleport.first && mX == mFirstTeleport.second) ||
			   (mY == mSecondTeleport.first && mX == mSecondTeleport.second);
	}
	else return false;

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMonster::teleport() {

	if (mFirstTeleport != mSecondTeleport) {
		if (mY == mFirstTeleport.first && mX == mFirstTeleport.second) {
			mY = mSecondTeleport.first;
			mX = mSecondTeleport.second;
		}
		else if (mY == mSecondTeleport.first && mX == mSecondTeleport.second) {
			mY = mFirstTeleport.first;
			mX = mFirstTeleport.second;			
		}
	}
	
	switch (mDirection) {
		case KEY_UP : {
			mY--;
			break;
		}
		case KEY_DOWN : {
			mY++;
			break;
		}
		case KEY_LEFT : {
			mX--;
			break;
		}
		case KEY_RIGHT : {
			mX++;
			break;
		}
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
