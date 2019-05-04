#include "IronArmour.h"
#include <iostream>

using namespace std;

IronArmour::IronArmour()
{
	this->id = 1;
	this->name = "Iron Armour";
}

IronArmour::~IronArmour()
{
}

void IronArmour::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void IronArmour::Function()
{
}




