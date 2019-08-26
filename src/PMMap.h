/**
	Contains all information about map
*/
#ifndef MAP
#define MAP


#include "fields/PMField.h"

#include <utility>
using namespace std;

class PMMap {

private:

	static const int ROWS = 31;						///< Maximal row count
	static const int COLUMNS = 28;					///< Maximal column count

	PMField *** mFields;							///< The map itself
	
	pair<int,int> mMonsterSpawn[4];					///< Monster spawn co-ordinates
	pair<int,int> mPacmanSpawn;						///< Pac-man spawn co-ordinates
	
	pair<int,int> mFirstTeleport;					///< TP co-odrinates
	pair<int,int> mSecondTeleport;
	
	int mFoodCNT;									///< Maximal quantity of food on the map
	
public:

	/**
		Constructor that allocates memory
	*/
	PMMap();										
	
	/**
		Cleaning all the allocated memory
	*/
	~PMMap();										 

	/**
		Drawing actual map
	*/	
	void drawMap() const;
	
	/**
		Returns Pac-man start position
	*/
	pair<int,int> getPacmanSpawn() const;			
	
	/**	
		Sets Pac-man start position
		\param p New pair of co-ordinates Y,X
	*/
	void setPacmanSpawn(pair<int, int>);			
	
	/**
		Returns enemie start positon
		\param i Index of the place from 0 to 3
	*/
	pair<int,int> getMonsterSpawn(int) const;		
	
	/**
		Sets enemie start position
		\param p Pair of co-ordinates Y,X
		\param i Index of the place from 0 to 3
	*/
	void setMonsterSpawn(pair<int, int>, int);		
	
	/**
		Returns pointer to fields
	*/
	PMField *** getFields() const;					
	
	/**
		Sets pointer to fields
	*/
	void setFields(PMField ***);					
	
	/**
		Checks whether it's possible to move on a given field
		\param y Y co-ordinate of the field
		\param x X co-ordinate of the field
	*/
	bool access(int, int) const;	 				
	
	/**
		Gets maximal quantity of food on the map
	*/
	int getFoodCNT() const;							
	
	/**
		Sets maximal quantity of food on the map
	*/
	void setFoodCNT(int);							
	
	/**
		Sets co-ordinates of the first teleport
	*/
	void setFirstTeleport(pair<int,int>);			
	
	/**
		Sets co-ordinates of the second teleport
	*/
	void setSecondTeleport(pair<int,int>);			
	
	/**
		Gets co-ordinates of the first teleport
	*/
	pair<int,int> getFirstTeleport() const;			
	
	/**
		Gets co-ordinates of the second teleport
	*/
	pair<int,int> getSecondTeleport() const;		

};


#endif // MAP
