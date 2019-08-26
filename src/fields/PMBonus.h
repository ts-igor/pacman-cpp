/**
	Bonus field that changes game mode
*/
#ifndef BONUS
#define BONUS


#include "PMField.h"
#include "../units/PMPacman.h"

class PMBonus : public PMField {

private:

public:
	PMBonus(int, int);
	~PMBonus();
	
	/**
		Interacting with Pacman
		Makes him to change game mode
	*/
	virtual void interact(PMPacman *);								
	
	/**
		Drawing bonus field
	*/
	virtual void drawField(WINDOW *) const;							
	
};


#endif // BONUS
