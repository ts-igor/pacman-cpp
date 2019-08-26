/**
	Those dots on the map that Pac-Man eats
*/
#ifndef FOOD
#define FOOD


#include "PMField.h"
#include "../units/PMPacman.h"

class PMFood : public PMField {

private:

public:
	PMFood(int, int);
	~PMFood();
	
	/**
		Increases Pac-Man's score and fades
	*/
	void virtual interact(PMPacman *);									
	
};


#endif // FOOD
