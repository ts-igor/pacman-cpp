/**
	That pink ghost
*/
#ifndef PINKY
#define PINKY


#include "PMMonster.h"
#include "PMPacman.h"

#include <ncurses.h>

class PMPinky : public PMMonster {

private:
	
	/**
		Draws Pinky
	*/
	virtual void draw() const;

public:

	PMPinky(PMMap &, int, PMPacman *);
	~PMPinky();
	
	/**
		Chases 4 points in front of Pac-Man
	*/
	virtual void chase();

};


#endif // PINKY
