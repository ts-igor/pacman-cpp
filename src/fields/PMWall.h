/**
	Blocks movement
*/
#ifndef WALL
#define WALL


#include "PMField.h"
#include "../units/PMPacman.h"

class PMWall : public PMField {

private:

public:
	PMWall(int, int);
	~PMWall();

	/**
		Does not interact with anyone
	*/
	virtual void interact(PMPacman *);
	
	/**
		Draws Wall field
	*/
	virtual void drawField(WINDOW *) const;
	
	/**
		Tells that no one can step on this wall
	*/
	virtual bool accessField() const;	

};


#endif // WALL
