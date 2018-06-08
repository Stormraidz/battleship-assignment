/****************************************************************************************************************************************************************************************
** Author: Riley Prince
** Date: 6/4/2018
** Description:  BBoard class for Assignment 5
****************************************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include "Ship.hpp"
#include "BBoard.hpp"
using std::string;

BBoard::BBoard()					// Assigns values to both arrays
{
	for ( int i = 1; i <= 10; i++ )
	{
		for ( int n = 1; n <= 10; n++)
		{
			bArray[i][n] = false;	// initializes array to false
			sArray[i][n] = NULL;
			//std::cout << sArray[i][n] << std::endl;	// ini8tializes array of pointers to NULL
		}
	}
}
bool BBoard::placeShip(Ship* shipptr, int x, int y, char orientation) // Takes in Ship object Pointer, coordinates, and orientation
{ // Because all ships are oriented away from origin only 2 directions are needed for orientation down (row) or right (column)
	bool valid = true;
	if (sArray[x][y] == NULL)		//Checks if ship already exists here
	{
		if ( orientation == 'c' && ( ((y + shipptr->getLength()) > ysize)))		// Checks Validity of move
		{
			valid = false;
		}
		else if ( orientation == 'r' && ( ((x + shipptr->getLength()) > xsize)))	// Checks validity of move
		{
			valid = false;
		}
		else				// if Move deemed valid...
		{
			if (orientation == 'c' )
			{
				for ( int i = 0; i < shipptr->getLength(); i++)			// Checks if any pointers are assigned to these coordinates
				{
					if (sArray[x][y+i] != NULL)
					{
						valid = false;
						return valid;
					}
				}
				for ( int i = 0; i < shipptr->getLength(); i++)			// If still valid places ship on pointer array
				{
					sArray[x][y+i] = shipptr;
				}
			}
			else
			{
				for ( int i = 0; i < shipptr->getLength(); i++)			// checks if pointer array is occupied or not
				{
					if (sArray[x+i][y] != NULL)
					{
						valid = false;
						return valid;
					}
				}
				for ( int i = 0; i < shipptr->getLength(); i++)			// If still valid places ship into pointer array
				{
					sArray[x + i][y] = shipptr;
				//	std::cout << sArray << std::endl;
				}
			}
		}
	}
	else
	{
		valid = false;
	}
	return valid;
}
int BBoard::getNumShipsRemaining()
{
	return unSunk;				// returns how many ships are left
}
Ship* BBoard::getShipsArrayElement(int x, int y)  	// Takes in ship  coordinates
{
	Ship* shipPtr = sArray[x][y];
	
	return shipPtr;			// returns the element in the ship-pointer array
}
bool BBoard::getAttacksArrayElement( int x, int y ) 	// Takes in ship coordinates
{
	return bArray[x][y];			// returns the element in the bool Array
}
bool BBoard::attack(int x, int y)			// Function for attacking ships
{
	//std::cout << sArray[1][1] << " " << sArray[2][2] << std::endl;	
	bool hit;
	if (bArray[x][y] == false)		// Checks if board has already been attacked
	{
		if ( sArray[x][y] == NULL)	// If there is no pointer to hit at this location records hit function closes
		{
			bArray[x][y] = true;
			hit = false;	
		}
		else				// If there is a pointer to hit at this location calls pointer to ship object's take hit
		{
			bArray[x][y] = true;
			hit = true;
			sArray[x][y]->takeHit();
			if (sArray[x][y]->getLength() == sArray[x][y]->getDamage())	//if ship is sunk...  changes unsunk and tells player that a ship has sunk
			{
				unSunk = unSunk -1;
				std::cout << " You sunk " << sArray[x][y]->getName() << std::endl << unSunk << " Ships are remaining!";
			}
		}
	}
	else
	{
		hit = false;
		std::cout << "You ahve already attacked this spot" << std::endl;
	}
	return hit;
}

bool BBoard::allShipsSunk()				// Function Checks IF all ships in Object have sunk
{
	bool win = false;			// initializes false
	if (unSunk == 0)			// If number  of unsunk ships remaining is zero a player wins
	{
		win = true;
	}
	return win;
}
