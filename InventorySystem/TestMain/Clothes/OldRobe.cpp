#include "OldRobe.h"
#include <iostream>

using namespace std;

OldRobe::OldRobe()
{
	this->id = 2;
	this->name = "Old Robe";
}

OldRobe::~OldRobe()
{
}

void OldRobe::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void OldRobe::Function()
{
}




