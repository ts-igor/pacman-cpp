/**
	The red ghost
*/
#ifndef BLINKY
#define BLINKY


#include "PMMonster.h"
#include "PMPacman.h"

#include <ncurses.h>

class PMBlinky : public PMMonster {

private:

	/**
		Draws Blinky
	*/
	virtual void draw() const;

public:

	PMBlinky(PMMap &, int, PMPacman *);
	~PMBlinky();
	
	/**
		Chases Pac-Man
	*/
	virtual void chase();

};


#endif // BLINKY
