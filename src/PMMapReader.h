/**
	Class that was created for reading map
*/
#ifndef MAPREADER
#define MAPREADER


#include "PMMap.h"
#include "fields/PMField.h"
#include "fields/PMWall.h"
#include "fields/PMFood.h"
#include "fields/PMGreatFood.h"
#include "fields/PMBonus.h"
#include "fields/PMTeleport.h"
#include "fields/PMGround.h"

#include <utility>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

static const char * INCORRECT_STRUCTURE = "Incorrect file structure.\n"; ///< Error that will be thrown in the case of incorrect structure
static const char * UNABLE_TO_OPEN = "Unable to open the map file.\n";	///< Error that will be throw in the case of not finding map file

class PMMapReader {

private:
	
	static const int ROWS = 31;									///< Maximal row count
	static const int COLUMNS = 28; 								///< Maximal column count

	PMField *** mFields;
	PMMap * mMap;												///< Link to the main map
	
	
	/**
		Function checking if the file contains the string given as attribute
		\param s String that will be controlled to be
		\param in Input file stream
	*/
	void checkString(string, ifstream&) const;					
	
	/**
		Function checking the structure of co-ordinates and returning them
		\param in Input file stream
		\return Co-ordinates that were read
	*/
	pair<int,int> checkCoords(ifstream&) const;					 

public:
	
	PMMapReader(PMMap &);
	
	/**
		Reads map from the file
	*/
	void readMap() const;										

};


#endif // MAPREADER
