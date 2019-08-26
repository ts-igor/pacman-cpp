/**
	Gives a bit more score than a usual food
*/
#ifndef GREATFOOD
#define GREATFOOD


#include "PMField.h"
#include "../units/PMPacman.h"

class PMGreatFood : public PMField {

private:

public:
	PMGreatFood(int, int);
	~PMGreatFood();

	/**
		Increases Pac-Man's score and fades
	*/
	virtual void interact(PMPacman *);								
	
	/**
		Draws Great Food field
	*/
	virtual void drawField(WINDOW *) const;	

};


#endif // GREATFOOD
