/**
	Base class for all kinds of field
*/
#ifndef FIELD
#define FIELD


#include <ncurses.h>
class PMPacman;								// Early declaration for compilation purposes

class PMField {

protected:

	static int const X_SHIFT = 27;					///< X image shifting
	static int const Y_SHIFT = 9;					///< Y image shifting

	int mSymbol;							///< Symbol that will be printed for this type of field
	int posX;								///< Actual X co-ordinate position
	int posY;								///< Actual Y co-ordinate position

	bool mInteraction;						///< Tells whether it's possible to interact with this field
public:

	PMField(int, int);
	virtual ~PMField();						

	/**
		Makes field being possible to interact with Pac-Man
	*/
	virtual void interact(PMPacman *) = 0;	
	
	/**
		Drawing field
	*/
	virtual void drawField(WINDOW *) const;	
	
	/**
		Returns whether it's possible to move on this field or not
	*/
	virtual bool accessField() const;		
		
};


#endif // FIELD
