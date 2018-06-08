/******************************************************************************
** Author: Riley Prince
** Date: 6/4/2018
** Description: Ship Class For Assignment 5
*******************************************************************************/
#include <iostream>
#include <string>
using std::string;

class Ship{

	private:
		string name;
		int length, damage;

	public:
		Ship( string n, int l)
		{
			name = n, length = l, damage = 0;
		}
		int getLength()
		{
			return length;
		}
		int getDamage()
		{
			return damage;
		}
		string getName()
		{
			return name;
		}
		void takeHit()
		{
			damage = damage + 1;
		}
};
