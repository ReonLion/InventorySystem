#pragma once

#include "../../Items/PotionBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class MiddleHPPotion : public PotionBase
{
public:
	MiddleHPPotion();
	~MiddleHPPotion();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
