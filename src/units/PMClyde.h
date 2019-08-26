/**
	The orange ghost
*/
#ifndef CLYDE
#define CLYDE


#include "PMMonster.h"
#include "PMPacman.h"

#include <ncurses.h>

class PMClyde : public PMMonster {

private:

	/**
		Draws Clyde
	*/
	virtual void draw() const;

public:

	PMClyde(PMMap &, int, PMPacman *);
	~PMClyde();

	/**
		Chases Pac-Man if he's too far otherwise goes to left side of the bottom
	*/
	virtual void chase();

};


#endif // CLYDE
