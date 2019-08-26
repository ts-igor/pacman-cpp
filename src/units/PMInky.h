/**
	The blue ghost
*/
#ifndef INKY
#define INKY


#include "PMMonster.h"
#include "PMPacman.h"

#include <ncurses.h>
#include <cmath>

class PMInky : public PMMonster {

private:
	
	PMMonster * mBlinky;							///< Link to Blinky

	/**
		Draws Inky
	*/
	virtual void draw() const;
	
	/**
		Method for counting right position to chase
		\param b Blinky's co-ordinate
		\param p Pac-Man's direction +2 co-ordinate
	*/
	int findTarget(int, int) const;

public:

	PMInky(PMMap &, int, PMPacman *, PMMonster *);
	~PMInky();

	/**
		Chases target depending on Pac-Man's direction and Blinky's position
	*/
	virtual void chase();
	
};


#endif // INKY
