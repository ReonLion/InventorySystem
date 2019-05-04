#include "RusstyAxe.h"
#include <iostream>

using namespace std;

RusstyAxe::RusstyAxe()
{
	this->id = 2;
	this->name = "Russty Axe";
}

RusstyAxe::~RusstyAxe()
{
}

void RusstyAxe::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void RusstyAxe::Function()
{
}




