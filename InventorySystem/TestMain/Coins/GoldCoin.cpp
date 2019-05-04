#include "GoldCoin.h"
#include <iostream>

using namespace std;

GoldCoin::GoldCoin()
{
	this->id = 1;
	this->name = "Gold Coin";
}

GoldCoin::~GoldCoin()
{
}

void GoldCoin::Pickup(Backpack * p_backpack, int quantity)
{
	p_backpack->Pick(this, quantity);
}

void GoldCoin::Function()
{
}




