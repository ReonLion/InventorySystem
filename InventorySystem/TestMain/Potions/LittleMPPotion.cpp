#include "LittleMPPotion.h"
#include <iostream>

using namespace std;

LittleMPPotion::LittleMPPotion()
{
	this->id = 4;
	this->name = "Little MP Potion";
}

LittleMPPotion::~LittleMPPotion()
{
}

void LittleMPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void LittleMPPotion::Function()
{
}

