#include "PMMapReader.h"

//----------------------------------------------------------------------------------------------------------------------------------------
PMMapReader::PMMapReader(PMMap & map) {
	
	mFields = map.getFields();
	mMap = &map;

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMapReader::checkString(const string s, ifstream &in) const {

	char buff[255];
	
	in.getline(buff, 255);
	
	if (buff != s) throw INCORRECT_STRUCTURE;
	
}
//----------------------------------------------------------------------------------------------------------------------------------------
pair<int,int> PMMapReader::checkCoords(ifstream &in) const {

	char first[3];
	char second[3];
	char ch;
	
	// Reading the first number
	for (int i = 0; i < 2; i++) {
		in.get(first[i]);
	}
	first[2] = '\0';
	
	// Reading delimiter
	in.get(ch);
	if (ch != 'x') throw INCORRECT_STRUCTURE;
	
	// Reading the second number
	for (int i = 0; i < 2; i++) {
		in.get(second[i]);
	}
	second[2] = '\0';
	
	// End of the line check
	in.get(ch);
	if (ch != '\n') throw INCORRECT_STRUCTURE;
	
	try {
	
		// Converting read numbers to integer values
		int firstNumber = atoi(first);
		int secondNumber =  atoi(second);
		
		// Checking if the co-odrdinates are valid	
		if (firstNumber > ROWS || firstNumber < 0 ||
		    secondNumber > COLUMNS || secondNumber < 0)
		    	throw INCORRECT_STRUCTURE;
		
		pair<int,int> ret = make_pair(firstNumber,secondNumber);
		return ret;
			
	}
	catch (...) {
		throw INCORRECT_STRUCTURE;
	}

}
//----------------------------------------------------------------------------------------------------------------------------------------
void PMMapReader::readMap() const {

	int foodCNT = 0;
	vector< pair<int,int> > tps;

	const char * MAP_PATH = "src/map/map.txt";				

	// Opening file for reading
	ifstream in(MAP_PATH, ios::in );
	
	// Checking whether the file was opened
	if (! in.is_open()) {
		throw UNABLE_TO_OPEN;
	}
	
	// Reading the file's header and spawn co-ordinates
	checkString("Pac-man map", in);
	checkString("monster spawns:", in);
	for (int i = 0; i < 4; i++) {
		mMap->setMonsterSpawn(checkCoords(in), i);
	}
	checkString("pacman spawn:", in);
	mMap->setPacmanSpawn(checkCoords(in));
	
	// Reading the map
	char ch;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			in.get(ch);
			switch (ch) {
				case '#': {
					mFields[i][j] = new PMWall(i, j);
					break;
				}
				case '.': {
					mFields[i][j] = new PMFood(i, j);
					// Counting food
					foodCNT++;
					break;
				}
				case '?': {
					mFields[i][j] = new PMGreatFood(i, j);
					break;
				}
				case '@': {
					mFields[i][j] = new PMBonus(i, j);
					break;
				}
				case '/': {
					// Adding telports' co-ordinates to set them later
					tps.push_back( make_pair(i,j) );
					break;
				}
				case ' ': {
					mFields[i][j] = new PMGround(i, j);
					break;
				}
				default: throw INCORRECT_STRUCTURE;
			}	
		}
		// Additional check of the file structure
		in.get(ch);
		if (ch != '\n') throw INCORRECT_STRUCTURE; 
	}
	
	// Making teleports
	if (tps.size() == 2) {		
		mFields[ tps[0].first ][ tps[0].second ] = new PMTeleport( tps[0].first, tps[0].second, tps[1].first, tps[1].second );	
		mFields[ tps[1].first ][ tps[1].second ] = new PMTeleport( tps[1].first, tps[1].second, tps[0].first, tps[0].second );
		
		mMap->setFirstTeleport(tps[0]);
		mMap->setSecondTeleport(tps[1]);
	}
	else if (tps.size() == 0) {}
	// When it's not 2 or 0 teleports
	else throw INCORRECT_STRUCTURE;
	
	
	// Checking whether the end of file was reached
	in.get();
	if (!in.eof()) throw INCORRECT_STRUCTURE;
	
	// Closing the map file
	in.close();
	
	// Passing all the read fields and data to the main map
	mMap->setFields(mFields);
	mMap->setFoodCNT(foodCNT);

}
//----------------------------------------------------------------------------------------------------------------------------------------
