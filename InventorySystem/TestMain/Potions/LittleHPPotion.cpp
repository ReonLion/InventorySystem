#include "LittleHPPotion.h"
#include <iostream>

using namespace std;

LittleHPPotion::LittleHPPotion()
{
	this->id = 1;
	this->name = "Little HP Potion";
}

LittleHPPotion::~LittleHPPotion()
{
}

void LittleHPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void LittleHPPotion::Function()
{
}




