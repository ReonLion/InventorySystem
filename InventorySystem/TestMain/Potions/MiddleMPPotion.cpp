#include "MiddleMPPotion.h"
#include <iostream>

using namespace std;

MiddleMPPotion::MiddleMPPotion()
{
	this->id = 5;
	this->name = "Middle MP Potion";
}

MiddleMPPotion::~MiddleMPPotion()
{
}

void MiddleMPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void MiddleMPPotion::Function()
{

}

