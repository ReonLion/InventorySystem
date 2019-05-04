#include "GoldRing.h"
#include <iostream>

using namespace std;

GoldRing::GoldRing()
{
	this->id = 1;
	this->name = "Gold Ring";
}

GoldRing::~GoldRing()
{
}

void GoldRing::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void GoldRing::Function()
{
}




