#include "MagicSword.h"
#include <iostream>

using namespace std;

MagicSword::MagicSword()
{
	this->id = 3;
	this->name = "Magic Sword";
}

MagicSword::~MagicSword()
{
}

void MagicSword::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void MagicSword::Function()
{
}




