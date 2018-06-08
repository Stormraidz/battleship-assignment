/******************************************************************************
** Author: Riley Prince
** Date: 6/4/2018
** Description: Ship Class For Assignment 5
*******************************************************************************/
#include <iostream>
#include <string>
#include "Ship.hpp"

using std::string;
Ship::Ship( string n, int l)
{
	name = n, length = l, damage = 0;
}
int Ship::getLength()
{
	return length;
}
int Ship::getDamage()
{
	return damage;
}
string Ship::getName()
{
	return name;
}
void Ship::takeHit()
{
	damage = damage + 1;
}

