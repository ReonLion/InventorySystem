#pragma once

#include "../../Items/PotionBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class MiddleMPPotion : public PotionBase
{
public:
	MiddleMPPotion();
	~MiddleMPPotion();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
