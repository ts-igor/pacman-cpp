/**
	Makes possible to connect two parts of the map into a tunnel
*/
#ifndef TELEPORT
#define TELEPORT


#include "PMField.h"
#include "../units/PMPacman.h"
#include "../PMMap.h"

#include <utility>

class PMTeleport : public PMField {

private:

	int mTPY;														///< Y teleportation co-ordinate
	int mTPX;														///< X teleportation co-ordinate

	PMMap * mMap;

public:
	PMTeleport(int, int, int, int);
	~PMTeleport();
	
	/**
		Teleports Pac-man to another teleport
		\param p Link to Pac-Man
	*/
	virtual void interact(PMPacman *);								
	
	/**
		Sets teleportation co-ordinates
	*/
	void setTPCoords(pair<int,int>);								
	
	/**
		Returns co-ordinates of the teleport
	*/
	pair<int,int> getCoords() const;								
	
};


#endif // TELEPORT
