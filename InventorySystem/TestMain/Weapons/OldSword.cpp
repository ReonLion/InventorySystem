#include "OldSword.h"
#include <iostream>

using namespace std;

OldSword::OldSword()
{
	this->id = 1;
	this->name = "Old Sword";
}

OldSword::~OldSword()
{
}

void OldSword::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void OldSword::Function()
{
}




