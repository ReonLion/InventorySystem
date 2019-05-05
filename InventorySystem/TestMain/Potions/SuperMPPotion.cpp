#include "SuperMPPotion.h"
#include <iostream>

using namespace std;

SuperMPPotion::SuperMPPotion()
{
	this->id = 8;
	this->name = "Super MP Potion";
}

SuperMPPotion::~SuperMPPotion()
{
}

void SuperMPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void SuperMPPotion::Function()
{
}



