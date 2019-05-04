#include "MiddleHPPotion.h"
#include <iostream>

using namespace std;

MiddleHPPotion::MiddleHPPotion()
{
	this->id = 2;
	this->name = "Middle HP Potion";
}

MiddleHPPotion::~MiddleHPPotion()
{
}

void MiddleHPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void MiddleHPPotion::Function()
{
}

