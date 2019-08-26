/**
	Base class for describing all monster's base behaviour
*/
#ifndef MONSTER
#define MONSTER


#include "PMUnit.h"
#include "PMPacman.h"

#include <ncurses.h>
#include <set>
#include <cmath>
#include <cstdlib>

class PMMonster : public PMUnit {

protected:

	int mDirection;													///< Actual direction
	bool mDead;														///< Death indicator
	bool mSlow;														///< Slowing enemies in Scatter mode

	PMPacman * mPacman;												///< Link to Pac-man
	
	set< pair<int,int> > mShelter;									///< Set of shelter's fields co-ordinates 
	
	int countDirections() const;									///< Counts all possible directions except inversed one
	bool inShelter();												///< Checks whether has monster left the shelter on hasn't
	bool notShelter(int, int) const;								///< Checks whether given co-odrinates are in shelter co-ordinates
	
	pair<int,int> mFirstTeleport;									///< Co-odrinates of the first teleport
	pair<int,int> mSecondTeleport;									///< Co-odrinates of the second teleport
	
	/**
		Draws monster
	*/
	virtual void draw() const = 0;
	
	/**
		Counts distance between first Y,X co-ordinates and second ones
		\param y1 Y1
		\param x1 X1
		\param y2 Y2
		\param x2 X2
		\return Distance
	*/
	double countDistance(int, int, int, int) const;					
	
	/**
		Decides which way is best to turn towards given field
	*/
	void turn(int, int);											
	
	/**
		Does next step in one sided direction
	*/
	void step();													
	
	/**
		Random turn for scattering
	*/
	void randomTurn();												
	
	/**
		Goes up
	*/
	void turnUp();													
	
	/**	
		Goes down
	*/
	void turnDown();												
	
	/**
		Goes left
	*/
	void turnLeft();												
	
	/**
		Goes right
	*/
	void turnRight();												
	
	/**
		Checks access to the up field
	*/
	bool accessUp() const;											
	
	/**
		Checks access to the down field
	*/
	bool accessDown() const;										
	
	/**
		Checks access to the left field
	*/
	bool accessLeft() const;										
	
	/**
		Checks access to the right field
	*/
	bool accessRight() const;										
	
	/**
		Moves towards shelter
	*/
	void toShelter();												
	
	/**
		Tells if monster is on a teleport field
	*/
	bool onTeleport() const;										
	
	/**
		Teleportates to another teleport
	*/
	void teleport();												

public:

	PMMonster(PMMap &, int i, PMPacman *);
	virtual ~PMMonster();
	
	/**
		Says whether the enemie was eaten or not
	*/
	bool dead() const;
	
	/**
		Makes enemie dead
	*/												
	void getEaten();												
	
	/**
		Makes enemie alive
	*/
	void getAlive();												
	
	/**
		Chasing Pac-Man
	*/
	virtual void chase() = 0;										
	
	/**
		Running away
	*/
	virtual void scatter();											
	
};


#endif // MONSTER
