#include "PMGame.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMGame::PMGame() {
	
	mDifficulty = 2;
	
	// Changing the terminal size to fit game's resolution
	system("resize -s 43 80 1> /dev/null");
	
	// Initializing the ncurses library
	initscr();
	
	// Turning on color mode
	start_color();
	
	// Disabling line buffering
	cbreak();
	
	// Typed symbols doesn't show on the screen
	noecho();
	
	// Setting cursor invisible
	curs_set(0);

	// No delay for getch()
	nodelay(stdscr, TRUE);

}
//----------------------------------------------------------------------------------------------------------------------------------------
PMGame::~PMGame() {

	/*
	delete mPacman;
	for (int i = 0; i < 4; i++) {
		delete mMonster[i];
	}
	*/	

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::exitGame() {
	
	clear();
	
	attron(A_BOLD);
	mvprintw(18, 35, "BYE-BYE!");
	attroff(A_BOLD);
	
	refresh();
	system("sleep 1");
	
	// Finishing ncurses library functions
	endwin();
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::difficultySettings() {
	
	clear();
	refresh();
	mDifficulty = mMenu.drawDifficultySettings();

}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMGame::mainMenu() {
	
	clear();
	refresh();
	return mMenu.drawMainMenu();
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::printHealth() {

	int health = mPacman->getHealth();
	int x = 27;
	mvprintw(3, x, "                 ");
	mvprintw(3, x, "LIVES:");
	for (int i = 0; i < health; i++) {
		mvaddch(3, x+7+i, ACS_DIAMOND);
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::printScore() {

	mvprintw(2, 27, "SCORE: %d", mPacman->getScore());

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::printLevel() {

	mvprintw(2, 44, "LEVEL: %d", mLevel);

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::gameOver() {

	clear();
	
	attron(A_BOLD | COLOR_PAIR(1));
	mvprintw(18, 35, "GAME OVER");
	mvprintw(19, 31, "YOUR SCORE IS: %d", mPacman->getScore());
	attroff(A_BOLD | COLOR_PAIR(1));
	
	refresh();
	system("sleep 2");	

}
//----------------------------------------------------------------------------------------------------------------------------------------
int PMGame::keyFilter(int previous) const {
	
	int c = getch();
	switch (c) {
		case KEY_UP : return c;
		case KEY_DOWN : return c;
		case KEY_LEFT : return c;
		case KEY_RIGHT : return c;
		case ESCAPE_KEY : return c;
	}
	return previous;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::playGame() {

	int actualHealth = mPacman->getHealth();
	while (actualHealth > 0) {													
	
		actualHealth = mPacman->getHealth();
		printHealth();
		printLevel();
	
		// Default direction is left
		int keyPressed = KEY_LEFT;
		startPositions();
		system("sleep 3");
	
		for (int i = 0; i < mDifficulty; i++) {									// Making all monsters alive
			mMonster[i]->getAlive();
		}
	
		// While Pac-man isn't hit and there's still food on the map
		while (actualHealth == mPacman->getHealth() && mMap.getFoodCNT() != mPacman->foodEaten() ) {
		
			keypad(stdscr, TRUE);
			mMap.drawMap();		
	
			// One Pac-man step
			mPacman->move(keyPressed);
			
			if (mPacman->scatterMode()) {
				for(int i = 0; i < mDifficulty; i++) {
					mMonster[i]->scatter();
					if (mMonster[i]->getCoords() == mPacman->getCoords() && !(mMonster[i]->dead())) {
						mPacman->addScore(400);
						mMonster[i]->getEaten();
						system("sleep 0.2");
					}
				}
			}
			else {
				for(int i = 0; i < mDifficulty; i++) {
					// Each enemie's one step
					mMonster[i]->chase();
					// Checking whether Pac-man was hit
					if (mMonster[i]->getCoords() == mPacman->getCoords() && !(mMonster[i]->dead())) {
						mPacman->decHealth();
					}
				}
			}
			
			printScore();
		
			keyPressed = keyFilter(keyPressed);
			// Leaving the game
			if (keyPressed == ESCAPE_KEY) break;
			
			refresh();
			system("sleep 0.3");
	
		}
		
		// Leaving the game
		if (keyPressed == ESCAPE_KEY) break;
		
		if (mMap.getFoodCNT() == mPacman->foodEaten()) {
			// Refreshing all the map's fields
			PMMapReader reader(mMap);					
			reader.readMap();
			
			mLevel++;
			// Sets food counter to zero
			mPacman->refreshFood();
			mPacman->scatterModeOff();	
			
		}
		
		system("sleep 2");
		
	}	

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::startPositions() {

	mMap.drawMap();
	mPacman->spawnPos();
	for (int i = 0; i < mDifficulty; i++) {
		mMonster[i]->spawnPos();
	}
	refresh();

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMGame::startGame() {

	// Starting from the first level
	mLevel = 1;

	// Reading a map file
	PMMapReader reader(mMap);
	reader.readMap();
	
	// Passing co-odrinates of spawn positons and creating objects
	mPacman = new PMPacman(mMap);
	
	mMonster[0] = new PMBlinky(mMap, 0, mPacman);
	mMonster[1] = new PMPinky(mMap, 1, mPacman);
	mMonster[3] = new PMInky(mMap, 2, mPacman, mMonster[0]);
	mMonster[2] = new PMClyde(mMap, 3, mPacman);
	
	clear();

	playGame();
	system("sleep 2");
	
	gameOver();
	
	delete mPacman;
	for (int i = 0; i < 4; i++) {
		delete mMonster[i];
	}
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
