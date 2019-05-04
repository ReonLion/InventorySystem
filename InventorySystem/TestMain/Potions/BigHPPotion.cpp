#include "BigHPPotion.h"
#include <iostream>

using namespace std;

BigHPPotion::BigHPPotion()
{
	this->id = 3;
	this->name = "Big HP Potion";
}

BigHPPotion::~BigHPPotion()
{
}

void BigHPPotion::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void BigHPPotion::Function()
{
}

