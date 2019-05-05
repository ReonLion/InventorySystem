#include "SuperHPPotion.h"
#include <iostream>

using namespace std;

SuperHPPotion::SuperHPPotion()
{
	this->id = 7;
	this->name = "Super HP Potion";
}

SuperHPPotion::~SuperHPPotion()
{
}

void SuperHPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void SuperHPPotion::Function()
{
}

