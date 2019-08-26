/**
	Just an empty place to walk on
*/
#ifndef GROUND
#define GROUND


#include "PMField.h"
#include "../units/PMPacman.h"

class PMGround : public PMField {

private:

public:
	PMGround(int, int);
	~PMGround();
	
	/**
		Does not interact with anyone
	*/
	virtual void interact(PMPacman *);
	
};


#endif // GROUND
