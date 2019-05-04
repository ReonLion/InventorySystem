#include "BigMPPotion.h"
#include <iostream>

using namespace std;

BigMPPotion::BigMPPotion()
{
	this->id = 6;
	this->name = "Big MP Potion";
}

BigMPPotion::~BigMPPotion()
{
}

void BigMPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void BigMPPotion::Function()
{
}



