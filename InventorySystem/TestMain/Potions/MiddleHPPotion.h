#pragma once

#include "../../Items/PotionBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class MiddleHPPotion : public PotionBase
{
public:
	MiddleHPPotion();
	~MiddleHPPotion();

	// 拾起道具
	void Pickup(Backpack* p_backpack, int quantity);

	// 道具的作用
	void Function() override;
};
