#pragma once

#include "../../Items/CoinBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class SilverCoin : public CoinBase
{
public:
	SilverCoin();
	~SilverCoin();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
