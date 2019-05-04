#include "SilverRing.h"
#include <iostream>

using namespace std;

SilverRing::SilverRing()
{
	this->id = 2;
	this->name = "Silver Ring";
}

SilverRing::~SilverRing()
{
}

void SilverRing::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void SilverRing::Function()
{
}




