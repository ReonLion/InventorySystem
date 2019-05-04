#include "CopperRing.h"
#include <iostream>

using namespace std;

CopperRing::CopperRing()
{
	this->id = 3;
	this->name = "Copper Ring";
}

CopperRing::~CopperRing()
{
}

void CopperRing::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void CopperRing::Function()
{
}




