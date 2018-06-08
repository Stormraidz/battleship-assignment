/******************************************************************************
** Author: Riley Prince
** Date: 6/4/2018
** Description: Ship Class For Assignment 5
*******************************************************************************/
#ifndef _SHIP_HPP_
#define _SHIP_HPP_
#include <string>
#include <iostream>
using std::string;

class Ship
{

	private:
		string name;
		int length, damage;

	public:
		Ship( string n, int l);

		int getLength();

		int getDamage();

		string getName();

		void takeHit();

};
#endif
