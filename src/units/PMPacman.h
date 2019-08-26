/**
	Who's that pokemon?
*/
#ifndef PACMAN
#define PACMAN


#include "PMUnit.h"
#include "../fields/PMField.h"

#include <ncurses.h>

class PMPacman : public PMUnit {

private:

	int mHealth;									///< HP counter
	int mScore;										///< Score counter
	int mDirection;									///< Actual direction
	int mEaten;										///< Eaten food counter
	
	bool mScatter;									///< Scatter mode indicator
	int mClock;										///< Clock for scatter mode
	
	PMField *** mFields;							///< Link to the fields

	/**
		Draws Pac-man
	*/
	virtual void draw() const;						
	
public:
	
	/**
		Sets HP counter on 2, score count on 0 and sets Pac-Man's symbol
	*/
	PMPacman(PMMap & map);							
	virtual ~PMPacman();
	
	/**
		Makes one move
	*/
	void move(int);									
	
	/**
		Changes main direction when it's possible
		\param k Key to change direction to
	*/
	void changeDirection(int);						
	
	/**
		Gets Pac-man's actual direction
		\return Code of the key
	*/
	int getDirection() const;							
	
	/**
		Changes Pac-man's co-ordinates
		\param y Y
		\param x X
	*/
	void changeCoordinates(int, int);				
	
	/**
		Returns healt counter
	*/
	int getHealth() const;							
	
	/**
		Decrements healt counter
	*/
	void decHealth();								
	
	/**
		Adding scores
		\param i Score to add
	*/
	void addScore(int);								
	
	/**
		Returns Pac-Man's score
	*/
	int getScore() const;							
	
	/**
		Returns quantity of eaten food
	*/
	int foodEaten() const;							
	
	/**
		Counts eaten food
	*/
	void eatFood();									
	
	/**
		Sets food counter to zero
	*/
	void refreshFood();								
	
	/**
		Turns on Scatter mode
	*/
	void scatterModeOn();							
	
	/**
		Tells whether it's scatter mode or not and counts time for it
	*/
	bool scatterMode();
	
	/**
		Turns off Scatter mode
	*/							
	void scatterModeOff();							

};


#endif // PACMAN
