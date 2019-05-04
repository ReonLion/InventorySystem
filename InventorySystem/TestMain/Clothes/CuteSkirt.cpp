#include "CuteSkirt.h"
#include <iostream>

using namespace std;

CuteSkirt::CuteSkirt()
{
	this->id = 3;
	this->name = "Cute Skirt";
}

CuteSkirt::~CuteSkirt()
{
}

void CuteSkirt::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void CuteSkirt::Function()
{
}




