/** 

	\brief Main class for the game
	
	Describes all playing methods and conditions

*/
#ifndef GAME
#define GAME


#include "units/PMPacman.h"
#include "PMMapReader.h"

#include "units/PMMonster.h"
#include "units/PMBlinky.h"
#include "units/PMPinky.h"
#include "units/PMInky.h"
#include "units/PMClyde.h"	

#include "PMMap.h"
#include "PMMenu.h"

#include <ncurses.h>
#include <cstdlib>
using namespace std;

static const int ESCAPE_KEY = 27;

class PMGame {

private:

	PMMenu mMenu;								///< Main menu
	PMMap mMap;									///< The map
	
	PMPacman * mPacman;							///< Pacman
	PMMonster * mMonster[4];					///< Monsters
	
	int mDifficulty;							///< Difficulty level
	int mLevel;									///< Game level
	
	/**
		Prints HP counter to the main screen
	*/
	void printHealth();
	
	/**
		Prints score to the main screen
	*/
	void printScore();							
	
	/**
		Prints level to the main screen
	*/
	void printLevel();							

	/**
		Takes back enemies and Pac-Man onto the start positions
	*/
	void startPositions();						
	
	/**
		Starts gaming process with appropriate difficulty level
	*/
	void playGame();							
	
	/**
		Prints player's score
	*/
	void gameOver();							

	/**
		Checks whether one of the arrow keys was pressed
		
		\param key Previous arrow key
		\return Pressed arrow key or previous one if it wasn't pressed
	*/
	int keyFilter(int) const;
	
public:

	PMGame();									///< Constructor that changes terminal size, sets lives count on 3 and difficulty on 2	
	~PMGame();									///< Cleans all created objects
	
	/**
		Shows main menu
	*/
	int	mainMenu();
	
	/**
		Starting a new game with a new map
	*/
	void startGame();							
	
	/**
		Difficulty settings menu
	*/
	void difficultySettings();					
	
	/**
		Finishing the game and closing the terminal
	*/
	void exitGame(); 
	
};


#endif // GAME
