#pragma once

#include "../../Items/CoinBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class GoldCoin : public CoinBase
{
public:
	GoldCoin();
	~GoldCoin();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
