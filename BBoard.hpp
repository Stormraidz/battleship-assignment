/****************************************************************************************************************************************************************************************
** Author: Riley Prince
** Date: 6/4/2018
** Description:  BBoard class for Assignment 5
****************************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include "Ship.hpp"
class BBoard
{
	private:
		const static int ysize = 10;
		const static int xsize = 10;
		bool bArray[xsize][ysize];										//bool  Array
		Ship* sArray[xsize][ysize];										// Ship -Pointer Array
		int unSunk;
	public:
		BBoard()														// Assigns values to both arrays
		bool placeShip(Ship* shipptr, int x, int y, char orientation)	// Takes in Ship object Pointer, coordinates, and orientation
		int getNumShipsRemaining()
		Ship* getShipsArrayElement(int x, int y)  						// Takes in ship  coordinates
		bool  getAttacksArrayElement( int x, int y )				 	// Takes in ship coordinates
		bool attack(int x, int y)										// Function for attacking ships
		bool allShipsSunk()												// Function Checks IF all ships in Object have sunk
};
