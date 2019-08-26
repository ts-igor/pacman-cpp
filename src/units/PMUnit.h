/**
	Base class for all units
*/
#ifndef UNIT
#define UNIT


#include "../PMMap.h"

#include <utility>
using namespace std;

class PMUnit {

protected:

	static int const X_SHIFT = 27;						///< X image shifting
	static int const Y_SHIFT = 9;						///< Y image shifting

	int mStartX;										///< Spawn X co-ordinate
	int mStartY;										///< Spawn Y co-ordinate
	
	int mX;												///< Actual X co-ordinate
	int mY;												///< Actual Y co-ordinate
	
	PMMap * mMap;										///< Link to the map
	
	int mSymbol;										///< Symbol that will be printed for this unit
	
	/**
		Draws unit with an appropriate symbol
	*/
	virtual void draw() const = 0;						

public:
	
	PMUnit(PMMap &);								
	virtual ~PMUnit();
	
	/**
		Returns a pair of co-ordinates
	*/
	pair<int,int> getCoords() const;					
	
	/**
		Gets unit onto the spawn position
	*/
	void spawnPos();									

};


#endif // UNIT
