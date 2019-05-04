#include "SilverCoin.h"
#include <iostream>

using namespace std;

SilverCoin::SilverCoin()
{
	this->id = 2;
	this->name = "Silver Coin";
}

SilverCoin::~SilverCoin()
{
}

void SilverCoin::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void SilverCoin::Function()
{
}




