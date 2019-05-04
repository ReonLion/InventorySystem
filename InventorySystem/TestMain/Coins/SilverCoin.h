#pragma once

#include "../../Items/CoinBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class SilverCoin : public CoinBase
{
public:
	SilverCoin();
	~SilverCoin();

	// 拾起道具
	void Pickup(Backpack* p_backpack, int quantity);

	// 道具的作用
	void Function() override;
};
