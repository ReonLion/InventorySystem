#pragma once

#include "../../Items/ClothBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class IronArmour : public ClothBase
{
public:
	IronArmour();
	~IronArmour();

	// 拾起道具
	void Pickup(Backpack* p_backpack, int quantity);

	// 道具的作用
	void Function() override;
};
