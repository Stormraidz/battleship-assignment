#include <iostream>
#include "BBoard.hpp"
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	BBoard board;
	Ship ship1("Boaty McBoatface", 2);
	board.placeShip(&ship1, 2, 2, 'r');
	cout << std::boolalpha << board.allShipsSunk() << endl;
	board.attack(2,2);
	cout << "damage = " << ship1.getDamage() << endl;
	board.attack(7,7);
	cout << std::boolalpha << board.allShipsSunk() << endl;
	board.attack(2,3);
	std::cout << "**" << std::endl;
	Ship* shipPtr = board.getShipsArrayElement(2,2); // segmentation fault unable to pass *Ship 

	return 0;
}
