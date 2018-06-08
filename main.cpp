#include <iostream>
#include "BBoard.hpp"
#include <string>
//#include "BBoard.hpp"
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
	board.attack(2,3);
	cout << std::boolalpha << board.allShipsSunk() << endl;
	board.attack(2,3);
	Ship* shipptr = board.getShipsArrayElement(2,3);

	return 0;
}
